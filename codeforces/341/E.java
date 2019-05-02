import java.util.*;
import java.io.*;

public class Candy {
    public static void main(String [] args) {
        Solver s = new Solver () ;
        s.solve();
    }
    static class Solver {
        int min_value(ArrayList <Pair> a) {
            int mn = Integer.MAX_VALUE;
            for(Pair i : a) {
                mn = Math.min(mn, i.first);
            }
            return mn;
        }
        void solve() {
            Reader in = new Reader ();
            Writer out = new Writer ();
            int n = in.nextInt();
            Pair [] a = new Pair [n + 1];
            for(int i = 1; i <= n; i++) {
                a[i] = new Pair();
                a[i].first = in.nextInt();
                a[i].second = i;
            }
            Arrays.sort(a, 1, n + 1, new Pair());

            if(a[n - 1].first == 0) {
                System.out.println("-1");
                System.exit(0);
            }
            ArrayList <Pair> ans = new ArrayList <> ();
            ArrayList <Pair> can = new ArrayList <> ();
            can.add(a[n]);
            can.add(a[n - 1]);

            for(int i = n - 2; i >= 1; i--) {
                ArrayList <Pair> cur = new ArrayList <> ();
                cur.add(a[i]);
                cur.add(can.get(0));
                cur.add(can.get(1));
                Collections.sort(cur, new Pair());

                while(min_value(cur) > 0) {
                    int q = cur.get(1).first / cur.get(0).first;
                    for(int b = 0; b < 30; b++) {
                        if((1 << b) > q) break; 
                        if(((q >> b) & 1) == 1) {
                            cur.get(1).first -= cur.get(0).first;
                            cur.get(0).first <<= 1; 
                            ans.add(new Pair(cur.get(0).second, cur.get(1).second));
                        } else {
                            cur.get(2).first -= cur.get(0).first;
                            cur.get(0).first <<= 1;
                            ans.add(new Pair(cur.get(0).second, cur.get(2).second));
                        }
                    }
                    Collections.sort(cur, new Pair());
                } 
                can.clear();
                for(Pair x : cur) {
                    if(x.first != 0) {
                        can.add(x);
                    }
                }
            }
            System.out.println(ans.size());
            for(Pair i : ans) {
                System.out.println(i.first + " " + i.second);
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