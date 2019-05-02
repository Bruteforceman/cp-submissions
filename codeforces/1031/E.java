import java.util.*;
import java.io.*;

public class Triple {
    public static void main(String [] args) {
        Solver s = new Solver();
        s.solve();
    }
    static class Solver {
        int [] d = new int [1 << 6];
        Pair [] path = new Pair [1 << 6];
        int [] dist = new int [1 << 15];
        Pair [] way = new Pair [1 << 15]; 
        int [] a = new int [100010];

        void sixSolver() {
            int [] q = new int [1 << 6];
            Arrays.fill(d, -1);           
            int head = 0;
            int tail = 0;
            d[0] = 0;
            q[tail++] = 0;
            while(head < tail) {
                int x = q[head++];
                for(int i = 0; i < 6; i++) {
                    for(int j = i + 1; j < 6; j++) {
                        int m = x;
                        int dif = j - i;
                        int k = i - dif;
                        if(k >= 0) {
                            m ^= 1 << k;
                        }
                        m ^= 1 << i;
                        m ^= 1 << j;
                        if(d[m] == -1) {
                            d[m] = 1 + d[x];
                            path[m] = new Pair(i, j);
                            q[tail++] = m;
                        }
                    }
                }
                for(int i = 0; i < 6; i++) {
                    int m = x;
                    m ^= 1 << i;
                    if(d[m] == -1) {
                        d[m] = 1 + d[x];
                        path[m] = new Pair(-1, i);
                        q[tail++] = m;
                    }
                }
            }
        }
        void arbitrarySolver(int len) {
            int [] q = new int [1 << len];
            Arrays.fill(dist, -1);           
            int head = 0;
            int tail = 0;
            dist[0] = 0;
            q[tail++] = 0;
            while(head < tail) {
                int x = q[head++];
                for(int i = 0; i < len; i++) {
                    for(int j = i + 1; j < len; j++) {
                        int m = x;
                        int dif = j - i;
                        int k = i - dif;
                        if(k >= 0) {
                            m ^= 1 << k;
                            m ^= 1 << i;
                            m ^= 1 << j;
                            if(dist[m] == -1) {
                                dist[m] = 1 + dist[x];
                                way[m] = new Pair(i, j);
                                q[tail++] = m;
                            }
                        }
                    }
                }
            }
        }
        static class Data {
            int x, y, z;
            Data (int x, int y, int z) {
                this.x = x;
                this.y = y;
                this.z = z;
            }
            Data () {}
        }
        void solve() {
            Reader in = new Reader();
            Writer out = new Writer ();

            sixSolver();
            int n = in.nextInt();
            for(int i = 1; i <= n; i++) {
                a[i] = in.nextInt();
            }
            ArrayList <Data> ans = new ArrayList <> ();

            int cur = n;
            while(cur >= 14) {
                cur -= 5;
                int mask = 0;
                for(int i = cur; i < cur + 6; i++) {
                    if(a[i] == 1) {
                        mask |= 1 << (i - cur);
                    }
                }
                int now = mask;
                while(now != 0) {
                    int i = path[now].first;
                    int j = path[now].second;
                    int dif = j - i;
                    int k = i - dif;
                    ans.add(new Data(cur + k, cur + i, cur + j));
                    a[cur + k] ^= 1;
                    a[cur + i] ^= 1;
                    a[cur + j] ^= 1;
                    if(j >= 0) now ^= 1 << j;
                    if(i >= 0) now ^= 1 << i;
                    if(k >= 0) now ^= 1 << k;
                }
                --cur;
            }
            arbitrarySolver(cur);
            
            int mask = 0;
            for(int i = 1; i <= cur; i++) {
                if(a[i] == 1) {
                    mask |= 1 << (i - 1);
                }
            }
            if(dist[mask] == -1) {
                System.out.println("NO");
                System.exit(0);
            }

            int now = mask;
            cur = 1;
            while(now != 0) {
                int i = way[now].first;
                int j = way[now].second;
                int dif = j - i;
                int k = i - dif;
                ans.add(new Data(cur + k, cur + i, cur + j));
                a[cur + k] ^= 1;
                a[cur + i] ^= 1;
                a[cur + j] ^= 1;
                now ^= 1 << j;
                now ^= 1 << i;
                now ^= 1 << k;
            }
            System.out.println("YES");
            System.out.println(ans.size());
            for(Data i : ans) {
                System.out.println(i.x + " " + i.y + " " + i.z);
            }
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