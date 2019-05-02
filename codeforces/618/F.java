import java.util.*;
import java.io.*;

public class DoubleKnapscak {
    public static void main(String [] args) {
        Reader in = new Reader ();
        Writer out = new Writer ();
        int n = in.nextInt();
        long [] a = new long [n + 1];
        long [] b = new long [n + 1];

        for(int i = 1; i <= n; i++) {
            a[i] = in.nextInt();
            a[i] += a[i - 1];
        }
        for(int i = 1; i <= n; i++) {
            b[i] = in.nextInt();
            b[i] += b[i - 1];
        }
        boolean rev = (a[n] > b[n]);
        for(int i = 1; i <= n; i++) {
            if(a[n] > b[n]) {
                long tmp = a[i];
                a[i] = b[i];
                b[i] = tmp;
            }
        } 
        int opt[] = new int [n + 1];
        int last[] = new int [n + 1];
        Arrays.fill(last, -1);

        int pt = 0;
        ArrayList <Integer> arr[] = new ArrayList [2];
        arr[0] = new ArrayList <> ();
        arr[1] = new ArrayList <> ();

        for(int i = 0; i <= n; i++) {
            while(pt <= n && b[pt] <= a[i]) {
                ++pt;
            }
            opt[i] = pt - 1;
            int dif = (int)(a[i] - b[opt[i]]);
            if(last[dif] == -1) {
                last[dif] = i;
            } else {
                for(int x = last[dif] + 1; x <= i; x++) {
                    arr[0].add(x);
                }
                for(int x = opt[last[dif]] + 1; x <= opt[i]; x++) {
                    arr[1].add(x);
                }
                break;
            }
        }
        int cur = rev ? 1 : 0;
        for(int i = 0; i < 2; i++) {
            out.writeln(arr[cur].size());
            for(Integer j : arr[cur]) {
                out.write(j + " ");
            }
            out.writeln("");
            cur ^= 1;
        }
        out.flush();
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