import java.math.*;
import java.util.*;

public class apple {
  static long dp[], a[], b[], cnt[];
  static ArrayList <Integer> leaf = new ArrayList <> ();
  static ArrayList <Integer> [] g;
  static long gcd(long a, long b) {
    if(b == 0) return a;
    return gcd(b, a % b);
  }
  static long lcm(long a, long b) {
    return (a / gcd(a, b)) * b;
  }
  static void dfs(int x, int par) {
    dp[x] = 1;
    cnt[x] = a[x];
    int child = 0;
    for(int i : g[x]) {
      if(i != par) {
        dfs(i, x);
        cnt[x] = cnt[x] + cnt[i];
        dp[x] = lcm(dp[x], dp[i]);
        child = child + 1;
      }
    }
    dp[x] = Math.max(child, 1) * dp[x];
    if(dp[x] > cnt[x]) {
      long sum = 0;
      for(long i : a) sum += i;
      System.out.println(sum);
      System.exit(0);
    }
  }
  static void propagate(int x, int par) {
    int child = 0;
    for(int i : g[x]) {
      if(i != par) {
        child = child + 1;
      }
    }
    if(child == 0) leaf.add(x);
    else {
      long value = b[x] / child;
      for(int i : g[x]) {
        if(i != par) {
          b[i] = value;
          propagate(i, x);
        }
      }
    }
  }
  public static void main (String [] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    a = new long [n];
    cnt = new long [n];
    b = new long [n];
    dp = new long [n];
    g = new ArrayList [n];

    for(int i = 0; i < n; i++) {
      a[i] = (long) in.nextInt();
    }
    for(int i = 0; i < n; i++) g[i] = new ArrayList <> ();
    for(int i = 0; i < n - 1; i++) {
      int u = in.nextInt() - 1;
      int v = in.nextInt() - 1;
      g[u].add(v); g[v].add(u);
    }
    dfs(0, -1);
    b[0] = dp[0];
    propagate(0, -1);
  
    long mxMult = (long) 1e18;
    for(int i : leaf) {
      mxMult = Math.min(mxMult, a[i] / b[i]);
    }
    long sum = 0;
    for(int i : leaf) {
      sum += a[i] - mxMult * b[i];
    }
    System.out.println(sum);
  }
}
