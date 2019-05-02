
import java.util.*;
import java.io.*;

public class CodePerm {
	public static void main(String[] args) {
		Solver s = new Solver();
		s.solver();
	}
	static class Data {
		int val, idx;
		Data () {};
		Data (int val, int idx) {
			this.val = val;
			this.idx = idx;
		}
	}
	static Data max(Data p, Data q) {
		return (p.val > q.val) ? new Data(p.val, p.idx) : new Data(q.val, q.idx);
	}
	static class Solver {
		final int inf = 1000000000;
		int pos[] = new int [500010];
		int a[] = new int [500010];
		Data t[] = new Data [500010 * 4];
		int n;
		
		boolean [] vis = new boolean [500010];
		int [] topsort = new int [500010];
		int pt;
		
		void update(int x, int val, int c, int b, int e) {
			if(b == e) {
				t[c] = new Data(val, b);
				return ;
			}
			int m = (b + e) >> 1;
			int l = c << 1;
			int r = l + 1;
			if(x <= m) {
				update(x, val, l, b, m);
			} else {
				update(x, val, r, m+1,e);
			}
			t[c] = max(t[l], t[r]);
		}
		Data query(int x, int y, int c, int b, int e) {
			if(x <= b && e <= y) {
				return t[c];
			}
			if(y < b || e < x) return new Data(0, 0);
			int l = c << 1;
			int r = l + 1;
			int m = (b + e) >> 1;
			return max(query(x, y, l, b, m), query(x, y, r, m+1, e));
		}
		void dfs(int x) {
			vis[x] = true;
			update(x, 0, 1, 1, n);
			if(pos[x] <= n && !vis[pos[x]]) {
				dfs(pos[x]);
			}
			while(true) {
				Data p = query(1, a[x], 1, 1, n);
				if(p.val > x) {
					dfs(p.idx);
				} else {
					break;
				}
			}
			topsort[pt++] = x;
		}
		void solver() {
			Reader in = new Reader();
			Writer out = new Writer();
			n = in.nextInt();
			for(int i = 1; i <= n+1; i++) {
				pos[i] = n+1;
			}
			for(int i = 1; i <= n; i++) {
				a[i] = in.nextInt();
				if(a[i] != -1) {
					pos[a[i]] = i;
				} else {
					a[i] = n + 1;
				}
			}
			for(int i = 0; i <= 4*n; i++) {
				t[i] = new Data(0, 0);
			}
			for(int i = 1; i <= n; i++) {
				update(i, pos[i], 1, 1, n);
			}
			for(int i = 1; i <= n; i++) {
				if(!vis[i]) {
					dfs(i);
				}
				// break;
			}
			int inv[] = new int [n+1];
			for(int i = 0; i < pt; i++)  {
				inv[topsort[i]] = i+1;
			}
			for(int i = 1; i <= n; i++) {
				out.write(inv[i] + " ");
			}
			out.writeln("");
			out.flush();
		}
	}
	static class Reader {
		private StringTokenizer a;
		private BufferedReader b;

		Reader() {
			a = null;
			b = new BufferedReader(new InputStreamReader(System.in));
		}

		public String next() {
			while (a == null || !a.hasMoreTokens()) {
				try {
					a = new StringTokenizer(b.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return a.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(this.next());
		}

		public long nextLong() {
			return Long.parseLong(this.next());
		}

		public double nextDouble() {
			return Double.parseDouble(this.next());
		}

		public String nextLine() {
			try {
				return b.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return "";
		}
	}

	static class Writer {
		private PrintWriter a;
		private StringBuffer b;

		Writer() {
			a = new PrintWriter(System.out);
			b = new StringBuffer("");
		}

		public void write(Object s) {
			b.append(s);
		}

		public void writeln(Object s) {
			b.append(s).append('\n');
		}

		public void flush() {
			a.print(b);
			a.flush();
			a.close();
		}
	}

	static class Pair implements Comparator<Pair> {
		int first;
		int second;

		Pair(int a, int b) {
			this.first = a;
			this.second = b;
		}

		Pair(Pair a) {
			this.first = a.first;
			this.second = a.second;
		}

		Pair() {
		}

		public String toString() {
			return "[" + first + ", " + second + "]";
		}

		public int compare(Pair a, Pair b) {
			if (a.first == b.first) {
				return a.second - b.second;
			} else {
				return a.first - b.first;
			}
		}
	}
}