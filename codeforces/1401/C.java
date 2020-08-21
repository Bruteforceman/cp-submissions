import java.util.*;
import java.io.*;

public class MereArray {
  public static void main(String [] args) {
    Reader in = new Reader();
    int t = in.nextInt();
    for(int cs = 0; cs < t; cs++) {
      int n = in.nextInt();
      Integer [] a = new Integer [n];
      for(int i = 0; i < n; i++) a[i] = in.nextInt();
      Integer [] b = a.clone();
      Arrays.sort(b);
      boolean good = true;
      for(int i = 0; i < n; i++) {
        if(a[i] % b[0] == 0 || a[i].equals(b[i])) continue;
        good = false;
      }
      if(good) System.out.println("YES");
      else System.out.println("NO");
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

