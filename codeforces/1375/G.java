import java.util.*;
import java.io.*;
public class TreeModification {
  public static void main(String [] args) {
    Reader in = new Reader();
    int n = in.nextInt();
    Graph graph = new Graph(n);
    for(int i = 1; i < n; i++) {
      int u = in.nextInt() - 1;
      int v = in.nextInt() - 1;
      graph.addEdge(u, v);
    }
    int [] count = graph.biColor();
    System.out.println(Math.min(count[0], count[1]) - 1);
  }
}
class Graph {
  ArrayList <Integer> [] g;
  int [] color;
  Graph(int size) {
    g = new ArrayList [size];
    color = new int [size];
    for(int i = 0; i < size; i++) {
      g[i] = new ArrayList <> ();
    }
  }
  void addEdge(int u, int v) {
    g[u].add(v);
    g[v].add(u);
  }
  void dfs(int x, int par) {
    for(int i : g[x]) {
      if(i != par) {
        color[i] = color[x] ^ 1;
        dfs(i, x);
      }
    }
  }
  int [] biColor() {
    color[0] = 0;
    dfs(0, -1);
    int [] count = new int [2];
    Arrays.fill(count, 0);
    for(int i = 0; i < color.length; i++) {
      count[color[i]] = count[color[i]] + 1;
    }
    return count;
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

