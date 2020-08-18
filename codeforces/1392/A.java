import java.util.*;
import java.io.*;

public class Password {
  public static void main(String args []) {
    Reader in = new Reader ();
    int t = in.nextInt();
    for(int cs = 1; cs <= t; cs++) {
      int n = in.nextInt();
      Integer [] a = new Integer [n];
      for(int i = 0; i < n; i++) {
        a[i] = in.nextInt();
      }
      Arrays.sort(a);
      if(a[0].equals(a[n - 1])) {
        System.out.println(n);
      } else {
        System.out.println(1);
      }
    }
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

