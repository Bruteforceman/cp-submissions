import java.util.*;
import java.io.*;

public class Landslide {
  public static void main(String [] args) {
    Reader in = new Reader();
    Writer out = new Writer();
    int n = in.nextInt();
    long [] h = new long[n];
    long sum = 0;
    for(int i = 0; i < n; i++) {
      h[i] = in.nextLong();
      sum += h[i] - i;
    }
    long first = (sum + n - 1) / n;
    int extra = (int)(first * n - sum);
    for(int i = 0; i < n; i++) h[i] = first + i;
    for(int i = n - extra; i < n; i++) h[i] -= 1;
    for(int i = 0; i < n; i++) {
      out.write(h[i]);
      out.write(" ");
    }
    out.writeLine("");
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
  long nextLong() {
    return Long.parseLong(next());
  }
}

class Writer {
  BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
  StringBuilder s = new StringBuilder("");
  void write(Object variable) {
    s.append(variable.toString());
  }
  void writeLine(Object variable) {
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

