import java.util.*;
import java.io.*;

public class TaxiFee {
    public static void main(String [] args) {
        Solver s = new Solver ();
        s.solve();
    }   
    static class Node implements Comparator <Node> {
        long dist;
        int v;
        Node () {}
        Node (long dist, int v) {
            this.dist = dist;
            this.v = v;
        }
        public int compare(Node p, Node q) {
            if(p.dist == q.dist) {
                return p.v - q.v;
            }
            return (p.dist < q.dist) ? -1 : 1;
        }
    }
    static class Solver {
        Reader in = new Reader ();
        Writer out = new Writer ();
        ArrayList <Integer> [] g = new ArrayList [200010];
        int l[] = new int [200010];
        int r[] = new int [200010];
        int w[] = new int [200010];
        long dist[] = new long [200010];
        long des[] = new long [200010];

        int par[] = new int [200010];
        final long inf = 1000000000000000000L;
        long ans[] = new long [200010];

        ArrayList <Integer> tree[] = new ArrayList [200010];
        int [][] anc = new int [20][200010];
        final int logn = 19;
        boolean tp[] = new boolean [200010];
        int [] dep = new int [200010];

        TreeSet <Node> sweep[] = new TreeSet [200010];

        void dfs(int x) {
            for(int i : tree[x]) {
                dep[i] = 1 + dep[x];
                dfs(i);
            }
        }
        int lca(int p, int q) {
            if(dep[p] > dep[q]) {
                int tmp = p;
                p = q;
                q = tmp;
            }
            for(int i = logn; i >= 0; i--) {
                if(dep[q] - (1 << i) >= dep[p]) {
                    q = anc[i][q];
                }
            }
            if(p == q) return p;
            for(int i = logn; i >= 0; i--) {
                if(anc[i][p] != anc[i][q]) {
                    p = anc[i][p];
                    q = anc[i][q];
                }
            }
            return anc[0][p];
        }

        void solve() {
            int n = in.nextInt();
            int m = in.nextInt();
            int qr = in.nextInt();
            for(int i = 0; i <= n; i++) {
                g[i] = new ArrayList <> ();
                tree[i] = new ArrayList <> ();
                sweep[i] = new TreeSet <> (new Node());
            }
            for(int i = 1; i <= m; i++) {
                int p = in.nextInt();
                int q = in.nextInt();
                int c = in.nextInt();
                g[p].add(i);
                g[q].add(i);
                l[i] = p;
                r[i] = q;
                w[i] = c;
            }
            Arrays.fill(dist, inf);
            TreeSet <Node> t = new TreeSet <> (new Node());
            t.add(new Node(0, 1));
            dist[1] = 0;

            while(!t.isEmpty()) {   
                long p = t.first().dist;
                int q = t.first().v;
                t.remove(new Node(p, q));
                for(int e : g[q]) {
                    int i = l[e] ^ r[e] ^ q;
                    if(dist[i] > p + w[e]) {
                        dist[i] = p + w[e];
                        t.add(new Node(dist[i], i));
                        par[i] = e;
                    }
                }
            }
            Arrays.fill(des, inf);
            t.add(new Node(0, n));
            des[n] = 0;
            while(!t.isEmpty()) {   
                long p = t.first().dist;
                int q = t.first().v;
                t.remove(new Node(p, q));
                for(int e : g[q]) {
                    int i = l[e] ^ r[e] ^ q;
                    if(des[i] > p + w[e]) {
                        des[i] = p + w[e];
                        t.add(new Node(des[i], i));
                    }
                }
            }
            for(int i = 2; i <= n; i++) {
                int e = par[i];
                int dad = l[e] ^ r[e] ^ i;
                tree[dad].add(i);
                anc[0][i] = dad;
            }
            dfs(1);
            for(int i = 1; i <= logn; i++) {
                for(int j = 1; j <= n; j++) {
                    anc[i][j] = anc[i - 1][anc[i - 1][j]];
                }
            }
            int cur = n;
            while(cur != 1) {
                int e = par[cur];
                tp[e] = true;
                cur ^= l[e] ^ r[e];
            }
            ArrayList <Integer> line = new ArrayList <> ();
            cur = 1;
            while(true) {
                line.add(cur);
                if(cur == n) break;
                for(int e : g[cur]) {
                    int i = l[e] ^ r[e] ^ cur;
                    if(tp[e] && dep[i] > dep[cur]) {
                        // System.out.println(cur + " " + i);
                        cur = i;
                        break;   
                    }
                } 
            }            
            int idx = 0;
            for(int i = 1; i <= m; i++) {
                if(tp[i]) continue;
                int p = lca(l[i], n);
                int q = lca(r[i], n);
                if(p == q) continue;
                if(dep[p] > dep[q]) {
                    int tmp = p;
                    p = q;
                    q = tmp;
                    tmp = r[i];
                    r[i] = l[i];
                    l[i] = tmp;
                }
                long cost = dist[l[i]] + w[i] + des[r[i]];
                sweep[dep[p]].add(new Node(cost, i));
                sweep[dep[q]].add(new Node(cost, -i));
                // System.out.println(p + " " + q + " " + cost);
            }

            // for(Node e : sweep[1]) {
            //     System.out.println(e.dist + " " + e.v);
            // }

            TreeSet <Node> cont = new TreeSet <> (new Node());
            for(int i = 0; i < line.size(); i++) {
                int node = line.get(i);
                if(node != 1) {
                    int e = par[node];
                    ans[e] = cont.isEmpty() ? inf : cont.first().dist;
                }
                for(Node j : sweep[i]) {
                    if(j.v > 0) {
                        cont.add(new Node(j.dist, j.v));
                    }
                }
                for(Node j : sweep[i]) {
                    if(j.v < 0) {
                        cont.remove(new Node(j.dist, -j.v));
                    }
                }
            }
            for(int i = 1; i <= m; i++) {
                if(!tp[i]) {
                    ans[i] = dist[n];
                }
            }
            // for(int i = 1; i <= m; i++) {
            //     if(tp[i]) {
            //         System.out.println(ans[i]);
            //     }
            // }
            for(int i = 1; i <= qr; i++) {
                int e = in.nextInt();
                int c = in.nextInt();
                int p = l[e];
                int q = r[e];
                long opt = Math.min(dist[p] + c + des[q], des[p] + c + dist[q]);
                opt = Math.min(opt, ans[e]);
                out.writeln(opt);
            }
            out.flush();
        }
    }
    static class Reader {
        private StringTokenizer a;
        private BufferedReader b;
        Reader () {
            a = null;
            b = new BufferedReader (new InputStreamReader (System.in));
        }
        public String next () {
            while(a == null || !a.hasMoreTokens()) {
                try {
                    a = new StringTokenizer (b.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return a.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(this.next());
        }
        public long nextLong () {
            return Long.parseLong(this.next());
        }
        public double nextDouble () {
            return Double.parseDouble(this.next());
        }
        public String nextLine() {
            try {
                return b.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return "";
        }
    }
    static class Writer {
        private PrintWriter a;
        private StringBuffer b;
        Writer () {
            a = new PrintWriter (System.out);
            b = new StringBuffer ("");
        }
        public void write (Object s) {
            b.append(s);
        }
        public void writeln(Object s) {
            b.append(s).append('\n');
        }
        public void flush () {
            a.print(b);
            a.flush();
            a.close();
        }
    }
    static class Pair implements Comparator <Pair> {
        int first;
        int second;
        Pair  (int a, int b) {
            this.first = a;
            this.second = b;
        }
        Pair (Pair a) {
            this.first = a.first;
            this.second = a.second;
        } 
        Pair () {}
        public String toString () {
            return "[" + first + ", " + second + "]";
        }
        public int compare (Pair a, Pair b) {
            if(a.first == b.first) {
                return a.second - b.second;
            } else {
                return a.first - b.first;
            }
        }
    } 
}