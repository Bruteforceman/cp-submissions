import java.util.*;
import java.io.*;

public class SwapSort {
  public static void main(String [] args) {
    Reader in = new Reader();
    Writer out = new Writer();
    int n = in.nextInt();
    int [] a = new int [n];
    int [] ord = new int [n];
    for(int i = 0; i < n; i++) {
      a[i] = in.nextInt();
      ord[i] = i;
    }
    ArrayList <Integer []> arr = new ArrayList <> ();
    for(int i = 0; i < n; i++) {
      for(int j = 1; j < n; j++) {
        if(a[ord[j - 1]] > a[ord[j]]) {
          Integer [] pair = {ord[j - 1] + 1, ord[j] + 1};
          arr.add(pair);
          int tmp = ord[j];
          ord[j] = ord[j - 1];
          ord[j - 1] = tmp;
        }
      }
    }
    out.writeln(arr.size());
    for(int i = arr.size() - 1; i >= 0; i--) {
      out.writeln(arr.get(i)[0] + " " + arr.get(i)[1]);
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
