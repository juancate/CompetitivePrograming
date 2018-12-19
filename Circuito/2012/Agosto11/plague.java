import java.io.*;
import java.util.*;

public class plague {
	static final boolean LOCAL = false;
	
	static void dbg(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter output = new PrintWriter(System.out);
		
		if(LOCAL)
			input = new BufferedReader(new FileReader("plague.in"));
		
		int Nm, Ni, Nc, n;
		while(true) {
			String[] l = input.readLine().split(" ");
			Nm = Integer.parseInt(l[0]);
			Ni = Integer.parseInt(l[1]);
			Nc = Integer.parseInt(l[2]);
			n = Integer.parseInt(l[3]);
			
			if((Nm|Ni|Nc|n) == 0)
				break;
			
			boolean deterministic = true;
			
			HashMap<String, String> m = new HashMap<String, String>();
			for(int i = 0; i < Nm; i++) {
				l = input.readLine().split(" ");
				if(m.containsKey(l[0]) && !m.get(l[0]).equals(l[1])) deterministic = false;
				else m.put(l[0], l[1]);
			}
			
			HashMap<String, Integer> x = new HashMap<String, Integer>();
			for(int i = 0; i < Ni; i++) {
				l = input.readLine().split(" ");
				x.put(l[0], Integer.parseInt(l[1]));
			}
			
			HashMap<String, Integer> c = new HashMap<String, Integer>();
			for(int i = 0; i < Nc; i++) {
				l = input.readLine().split(" ");
				c.put(l[0], Integer.parseInt(l[1]));
			}
			
			if(!deterministic) {
				output.println("Protein mutations are not deterministic");
				continue;
			}
			
			int ans = 0;
			//dbg("m = ", m);
			//dbg("c = ", c);
			while(ans <= n) {
				//dbg(x);
				if(x.equals(c))
					break;
				
				HashMap<String, Integer> cp = new HashMap<String, Integer>();
				
				for(String s : x.keySet()) {
					if(m.containsKey(s)) {
						int y = x.get(s);
						if(cp.containsKey(m.get(s)))
							y += cp.get(m.get(s));
						cp.put(m.get(s), y);
					}
				}

				for(String s : x.keySet()) {
					if(!m.containsKey(s)) {
						int y = x.get(s);
						if(cp.containsKey(s)) {
							y += cp.get(s);
						}
						cp.put(s, y);
					}
				}
				
				x = cp;

				ans++;
			}
			
			if(ans > n) {
				output.println("Nostalgia for Infinity is doomed");
			} else {
				output.printf("Cure found in %d mutation(s)\n", ans);
			}
		}
		
		output.close();
	}
}
