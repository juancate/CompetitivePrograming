import java.io.*;
import java.util.*;

public class trains {
	static final boolean LOCAL = false;
	
	static void dbg(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter output = new PrintWriter(System.out);
		
		if(LOCAL)
			input = new BufferedReader(new FileReader("trains.in"));
		
		while(true) {
			String[] ln = input.readLine().split(" ");
			
			n = Integer.parseInt(ln[0]);
			int ma = Integer.parseInt(ln[1]);
			int mb = Integer.parseInt(ln[2]);
			int k = Integer.parseInt(ln[3]);
			
			if(n == -1 && ma == -1 && mb == -1 && k == -1)
				break;
			
			GA = new long[n][n];
			GB = new long[n][n];
			
			for(int i = 0; i < n; i++) {
				Arrays.fill(GA[i], -1);
				Arrays.fill(GB[i], -1);
			}
			
			for(int i = 0; i < ma; i++) {
				ln = input.readLine().split(" ");
				int a = Integer.parseInt(ln[0]);
				int b = Integer.parseInt(ln[1]);
				long c = Integer.parseInt(ln[2]);
				
				GA[a][b] = GA[b][a] = c;
			}
			
			for(int i = 0; i < mb; i++) {
				ln = input.readLine().split(" ");
				int a = Integer.parseInt(ln[0]);
				int b = Integer.parseInt(ln[1]);
				long c = Long.parseLong(ln[2]);
				
				GB[a][b] = GB[b][a] = c;
			}
			
			for(int i = 0; i < k; i++) {
				double x = Double.parseDouble(input.readLine());
				output.println(dijkstra(0, n-1, x));
			}
		}
		
		output.close();
	}
	
	static long[][] GA, GB;
	static int n;

	static class State implements Comparable<State>{
		double cost;
		int node;

		public State() {
		}
		
		public State(double c, int n) {
			cost = c;
			node = n;
		}
		
		public int compareTo(State arg1) {
			return Double.compare(cost, arg1.cost);
		}
	}
	
	static long dijkstra(int source, int sink, double a) {
		double[] d = new double[n];
		
		Arrays.fill(d, 1e200);

		d[0] = 0.0;
		
		PriorityQueue<State> Q = new PriorityQueue<State>();
		Q.add(new State(0, source));
		
		while(!Q.isEmpty()) {
			State s = Q.poll();
			int v = s.node;
			
			if(s.cost > d[v]) continue;
			if(v == sink) return (long)Math.floor(s.cost);
			
			for(int u = 0; u < n; u++) {
				if(GA[v][u] == -1 && GB[v][u] == -1) continue;
				double diff;
				if(GA[v][u] != -1 && GB[v][u] != -1)
					diff = a * GA[v][u] + (1. - a) * GB[v][u];
				else
					diff = Math.max(GA[u][v], GB[v][u]);
				
				if(diff + s.cost < d[u]) {
					d[u] = diff + s.cost;
					Q.add(new State(diff + s.cost, u));
				}
			}
		}
		
		return -1;
	}
}

