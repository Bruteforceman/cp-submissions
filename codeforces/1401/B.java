import java.util.*;
import java.io.*;

public class TernarySeq {
  public static void main(String [] args) {
    Reader in = new Reader();
    int t = in.nextInt();
    for(int i = 0; i < t; i++) {
      int a[] = new int [3];
      int b[] = new int [3];
      for(int j = 0; j < 3; j++) a[j] = in.nextInt();
      for(int j = 0; j < 3; j++) b[j] = in.nextInt();
      long ans = 0;
      int twoOnePair = Math.min(a[2], b[1]);
      ans += twoOnePair * 2;
      a[2] -= twoOnePair;
      b[1] -= twoOnePair;
      a[1] -= Math.min(a[1], b[0] + b[1]);
      ans -= a[1] * 2;
      System.out.println(ans);
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

