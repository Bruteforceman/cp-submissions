import java.io.*;
import java.util.*;

public class ReplaceMex {
  public static void main(String [] args) {
    Reader in = new Reader();
    Writer out = new Writer();
    int t = in.nextInt();
    for(int cs = 0; cs < t; cs++) {
      int n = in.nextInt();
      int [] a = new int [n];
      for(int i = 0; i < n; i++) {
        a[i] = in.nextInt();
      }
      ArrayList <Integer> ans = solve(a);
      out.writeln(ans.size());
      for(int i = 0; i < ans.size(); i++) {
        out.write(ans.get(i) + 1);
        out.write(" ");
      }
      out.writeln("");
    }
    out.flush();
  }
  static ArrayList <Integer> solve(int [] a) {
    int n = a.length;
    ArrayList <Integer> sol = new ArrayList <> ();
    int [] cnt = new int [n + 1];
    while(true) {
      Arrays.fill(cnt, 0);
      for(int i = 0; i < n; i++) {
        cnt[a[i]] = cnt[a[i]] + 1;
      }
      int mex = 0;
      for(int i = 0; i <= n; i++) {
        if(cnt[i] == 0) {
          mex = i;
          break;
        }
      }
      if(mex < n) {
        a[mex] = mex;
        sol.add(mex);
      } else {
        int index = -1;
        for(int i = 0; i < n; i++) {
          if(a[i] != i) {
            index = i;
            break;
          }
        }
        if(index == -1) break;
        a[index] = mex;
        sol.add(index);
      }
    }
    return sol;
  }
}

class Reader {
  BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
  StringTokenizer s = new StringTokenizer("");
  Reader () {}
  String nextLine() {
    try {
      return in.readLine();
    } catch (Exception e) {
      e.printStackTrace();
      return "Error";
    }
  }
  String next() {
    while(!s.hasMoreTokens()) {
      s = new StringTokenizer(nextLine());
    }
    return s.nextToken();
  }
  int nextInt() {
    return Integer.parseInt(next());
  }
}

class Writer {
  BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
  StringBuilder s = new StringBuilder("");
  void write(Object variable) {
    s.append(variable.toString());
  }
  void writeln(Object variable) {
    write(variable);
    s.append("\n");
  }
  void flush() {
    try {
      out.write(new String(s));
      out.flush();
      out.close();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}
