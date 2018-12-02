import java.util.*;
import java.io.*;

public class Reception {
    public static void main(String [] args) {
        Solver s = new Solver();
        s.solve();
    }
}

class Data {
    long last, prev;
    Data () {}
    Data (long last, long prev) {
        this.last = last;
        this.prev = prev;
    }
}

class Solver {
    Reader in = new Reader ();
    Writer out = new Writer ();
    
    int [] a = new int [300010];
    long [] t = new long [4000010];
    long [] last = new long [4000010];
    final int maxn = 1000000;

    void update(int x, int d, int c, int b, int e) {
        if(b == e) {
            last[c] = x + d;
            return ;
        } 
        int m = (b + e) >> 1;
        int l = c << 1;
        int r = l + 1;
        if(x <= m) {
            update(x, d, l, b, m);
        } else {
            update(x, d, r, m+1, e);
        }
        long overlap = Math.max(0L, last[l] - (m + 1));
        t[c] = t[l] + Math.max(t[r] - overlap, 0L);
        last[c] = last[r] + Math.max(overlap - t[r], 0L);
        if(last[l] <= m) {
            t[c] += 1;
        }
    }
    void build(int c, int b, int e) {
        if(b == e) {
            t[c] = 0;
            last[c] = b;
            return ;
        }
        int m = (b + e) >> 1;
        int l = c << 1;
        int r = l + 1;
        build(l, b, m);
        build(r, m+1, e);
        last[c] = last[r];
        t[c] = t[l] + t[r] + 1;
    }

    Data query(int x, int c, int b, int e) {
        if(b == e) {
            // System.out
            return new Data(last[c], 0L);
        }
        int m = (b + e) >> 1;
        int l = c << 1;
        int r = l + 1;
        if(x <= m) {
            return query(x, l, b, m);
        } else {
            Data p = query(x, r, m+1, e);
            long overlap = Math.max(0L, last[l] - (m + 1));
            p.last += Math.max(0L, overlap - p.prev);
            p.prev = t[l] + Math.max(p.prev - overlap, 0L);
            if(last[l] <= m) {
                p.prev += 1;
            }
            return p;
        }
    }

    void solve () {
        build(1, 0, maxn);
        int q = in.nextInt();        
        // System.out.println(query(3, 1, 0, maxn).last);

        // System.exit(0);
        for(int i = 1; i <= q; i++) {
            String c = in.next();
            if(c.charAt(0) == '?') {
                int x = in.nextInt();
                Data p = query(x, 1, 0, maxn);
                System.out.println(p.last - x);
            } else if (c.charAt(0) == '+') {
                int x = in.nextInt();
                int d = in.nextInt();
                update(x, d, 1, 0, maxn);
                a[i] = x;
            } else {
                int id = in.nextInt();
                update(a[id], 0, 1, 0, maxn);
            }
        }
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
