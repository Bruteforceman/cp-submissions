import java.util.*;
import java.io.*;

public class Merge {
    public static void main(String [] args) {
        Solver s = new Solver();
        s.solve();
    }
}

class Solver {
    Reader in = new Reader ();
    Writer out = new Writer ();

    void solve () {
        int n = in.nextInt();
        int [] sz = new int [n];
        int [] mx = new int [n];
        int opt = 0;
        for(int i = 0; i < n; i++) {
            sz[i] = in.nextInt();
            for(int j = 1; j <= sz[i]; j++) {
                int x = in.nextInt();
                mx[i] = Math.max(mx[i], x);
                opt = Math.max(opt, x);
            }
        }
        long ans = 0;
        for(int i = 0; i < n; i++) {
            ans += 1L * sz[i] * (opt - mx[i]);
        }
        System.out.println(ans);
    }   
}

class Reader {
    private StringTokenizer a;
    private BufferedReader b;
    Reader () {
        a = null;
        try {
            b = new BufferedReader (new InputStreamReader (System.in)); // for file IO, replace this with new FileReader ("in.txt")
        } catch (Exception e) {
            e.printStackTrace();
        }
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
class Writer {
    private PrintWriter a;
    private StringBuffer b;
    Writer () {
        try {
            a = new PrintWriter (System.out); // for file IO, replace this with new FileWriter ("out.txt")
        } catch (Exception e) {
            e.printStackTrace();
        }        
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
class Pair implements Comparator <Pair> {
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