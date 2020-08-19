import java.util.*;
import java.io.*;

public class Extermination {
  public static void main(String [] args) {
    Reader in = new Reader();
    Writer out = new Writer();
    int t = in.nextInt();
    for(int cs = 0; cs < t; cs++) {
      int n = in.nextInt();
      int [] a = new int [n];
      for(int i = 0; i < n; i++) a[i] = in.nextInt();
      if(a[0] < a[n - 1]) {
        out.writeln("YES");
      } else {
        out.writeln("NO");
      }
    }
    out.flush();
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
