import java.util.*;
import java.io.*;

public class Bracket {
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
        String txt = in.next();
        char [] s = txt.toCharArray();
        int [] p = new int [n + 2];
        Arrays.fill(p, -1);

        int sum = 0;
        p[0] = 0;
        for(int i = 1; i <= n; i++) {
            if(s[i-1] == '(') ++sum;
            else --sum;
            if(sum < 0) break;
            p[i] = sum;
        } 

        int opt = 0;
        sum = 0;
        int ans = 0;
        for(int i = n; i >= 1; i--) {
            int c = s[i-1] == '(' ? -1 : 1;
            if(p[i-1] >= 0 && p[i-1] + c >= -opt && p[i-1] + c + sum == 0) {
                ++ans;
            }
            sum -= c;
            opt = Math.min(0, opt - c);
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