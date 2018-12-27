import java.util.*;
import java.io.*;

public class Circular {
    public static void main(String [] args) {
        Solver s = new Solver();
        s.solve();
    }
}

class Solver {
    Reader in = new Reader ();
    Writer out = new Writer ();
    ArrayList <Integer> [] g = new ArrayList [200010];
    boolean [] vis = new boolean [200010];
    ArrayList <Integer> ans;

    void dfs(int x) {
        ans.add(x);
        vis[x] = true;
        for(Integer i : g[x]) {
            if(!vis[i]) {
                dfs(i);
                break;
            }
        }
    }

    void solve () {
        int n = in.nextInt();
        for(int i = 0; i <= n; i++) {
            g[i] = new ArrayList <> ();
        }
        int p1 = 0, p2 = 0;
        for(int i = 1; i <= n; i++) {
            int p = in.nextInt();
            int q = in.nextInt();
            g[p].add(q);
            g[q].add(p);
            if(i == 1) {
                p1 = p;
                p2 = q;
            }
        }
        Arrays.fill(vis, false);
        ans = new ArrayList <> ();
        dfs(1);
        boolean rev = true;
        for(int i = 0; i < ans.size(); i++) {
            if(ans.get(i) == 1) {
                if(ans.get((i + 1) % n) == p1 || ans.get((i + 1) % n) == p2) {
                    rev = false;
                    break;
                }
            }
        }
        if(!rev) {
            for(int i = 0; i < n; i++) {
                out.write(ans.get(i) + " ");
            }
        } else {
            for(int i = n-1; i >= 0; i--) {
                out.write(ans.get(i) + " ");
            }
        }
        out.writeln("");
        out.flush();
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