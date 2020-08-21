import java.util.*;
import java.io.*;

public class DistributeTree {
  public static void main(String [] args) {
    Reader in = new Reader();
    int test = in.nextInt();
    final int mod = 1000000000 + 7;
    for(int cs = 0; cs < test; cs++) {
      int n = in.nextInt();
      Graph tree = new Graph(n);
      for(int i = 1; i < n; i++) {
        int u = in.nextInt() - 1;
        int v = in.nextInt() - 1;
        tree.join(u, v);
      }
      long [] cnt = tree.getCount();
      int m = in.nextInt();
      Integer [] factor = new Integer [m];
      for(int i = 0; i < m; i++) factor[i] = in.nextInt();
      Arrays.sort(factor); 
      long [] weight = new long [n - 1];
      Arrays.fill(weight, 1);
      if(m <= n - 1) {
        for(int i = 0; i < m; i++) weight[i] = factor[i];
      } else {
        for(int i = 0; i < n - 1; i++) {
          weight[i] = factor[i];
        }
        for(int i = n - 1; i < m; i++) {
          weight[n - 2] *= factor[i];
          weight[n - 2] %= mod;
        }
      }
      Long [] sortW = new Long [n - 1];
      for(int i = 0; i < n - 1; i++) sortW[i] = -weight[i];
      Arrays.sort(sortW);
      long ans = 0;
      for(int i = 0; i < n - 1; i++) {
        ans += -sortW[i] * cnt[i];
        ans %= mod;
      }
      System.out.println(ans);
    }
  }
}
class Graph {
  int size;
  ArrayList <Integer> [] g;
  Long [] cnt;
  int [] sub;

  Graph (int size) {
    this.size = size;
    g = new ArrayList [size];
    sub = new int [size];
    cnt = new Long [size];
    for(int i = 0; i < size; i++) {
      g[i] = new ArrayList <> ();
    }
  }
  void join(int x, int y) {
    g[x].add(y);
    g[y].add(x);
  }
  void dfs(int x, int par) {
    sub[x] = 1;
    for(int i : g[x]) {
      if(i != par) {
        dfs(i, x);
        sub[x] += sub[i];
      }
    }
    cnt[x] = -1L * sub[x] * (size - sub[x]);
  }
  long [] getCount() {
    dfs(0, -1);
    Arrays.sort(cnt);
    long [] ret = new long [size - 1];
    for(int i = 0; i < size - 1; i++) ret[i] = -cnt[i];
    return ret;
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

