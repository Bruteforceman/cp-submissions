import java.util.*;
import java.io.*;

public class DistanceAxis {
  public static void main(String [] args) {
    Reader in = new Reader ();
    int t = in.nextInt();
    for(int i = 0; i < t; i++) {
      int n = in.nextInt();
      int k = in.nextInt();
      int value = Math.max(n, k);
      int ans = Math.abs(value - n);
      if(value % 2 != k % 2) ++ans;
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

