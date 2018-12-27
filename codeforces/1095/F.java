import java.util.*;
import java.io.*;

public class Connected {
    public static void main(String [] args) {
        Solver s = new Solver();
        s.solve();
    }
}

class Dsu {
    int [] par;
    int [] sub;
    Dsu (int sz) {
        par = new int[sz + 10];
        sub = new int[sz + 10];
        for(int i = 0; i <= sz; i++) {
            par[i] = i;
            sub[i] = 1;
        }
    }
    int root(int x) {
        if(x == par[x]) return x;
        return par[x] = root(par[x]);
    }
    void join(int p, int q) {
        p = root(p);
        q = root(q);
        if(sub[p] > sub[q]) {
            int tmp = p;
            p = q;
            q = tmp;
        }
        if(p != q) {
            par[p] = q;
            sub[q] += sub[p];
        }
    }
}
class Edge implements Comparator <Edge> {
    int u, v;
    long cost;
    Edge (int u, int v, long cost) {
        this.u = u;
        this.v = v;
        this.cost = cost;
    }
    Edge () {}
    public int compare(Edge a, Edge b) {
        if(a.cost == b.cost) return 0;
        else if (a.cost < b.cost) return -1;
        else return 1;
    }
}
class Solver {
    Reader in = new Reader ();
    Writer out = new Writer ();
    long [] a = new long [200010];

    void solve () {
        int n = in.nextInt();
        int m = in.nextInt();

        int opt = 1;
        for(int i = 1; i <= n; i++) {
            a[i] = in.nextLong();
            if(a[opt] > a[i]) {
                opt = i;
            }
        }
        ArrayList <Edge> e = new ArrayList <> ();
        for(int i = 1; i <= m; i++) {
            int p, q;
            long c;
            p = in.nextInt();
            q = in.nextInt();
            c = in.nextLong();
            e.add(new Edge(p, q, c));
        }
        for(int i = 1; i <= n; i++) {
            e.add(new Edge(opt, i, a[opt] + a[i]));
        }
        Collections.sort(e, new Edge());
            
        long ans = 0;
        Dsu t = new Dsu (n);
        for(Edge i : e) {
            if(t.root(i.u) != t.root(i.v)) {
                ans += i.cost;
                t.join(i.u, i.v);
            }
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