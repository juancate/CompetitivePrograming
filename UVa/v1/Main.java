import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


// 112 - Tree Summing
// Algorithm : Recurtion 

public class Main {
	static BufferedReader input;
	static StringTokenizer _stk;
	
	static String readln()  {
		String l = "";
		try {
			l = input.readLine();
			
			if(l != null) {
				l = l.replace("()", " ( "+Integer.toString(Integer.MAX_VALUE) + " ) ");
				l = l.replace("(", " ( ");
				l = l.replace(")", " ) ");
				_stk = new StringTokenizer(l, " ");
			}
		} catch (Exception e) {}
		return l;
	}
	
	static String next() {
		if(_stk.hasMoreTokens())
			return _stk.nextToken();
		return null;
	}
	
	static int nextInt() {
		return Integer.parseInt(next());
	}
	
	static void dbg(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}
	
	static Tree parse() {
		String val = "";
		while(!_stk.hasMoreTokens())
			readln();
		val = next(); // check Tree multiline (
		
		Tree t;
		
		int num = 0;
		while(!_stk.hasMoreTokens())
			readln();
		num = nextInt();
		
		if(num == Integer.MAX_VALUE) {
			while(!_stk.hasMoreTokens())
				readln();
			val = next(); // )	
			return null;
		}
		
		t = new Tree(num, parse(), parse());
		while(!_stk.hasMoreTokens())
			readln();
		val = next(); // )
		 
		return t;
	}
	
	
	static boolean match(Tree t, int sum, int acc) {
		if(t == null) return false;
		
		if(t.left == null && t.right == null) return (sum == acc + t.N); // leaft
		
		if(match(t.left, sum, acc + t.N)) return true;
		if(match(t.right, sum, acc + t.N)) return true;
		return false;
	}
	
	public static void main(String[] args) throws Exception {
		input = new BufferedReader(new InputStreamReader(System.in));
		String l = null;
		while((l = readln()) != null) {
			while(!_stk.hasMoreTokens()) {
				l = readln();
				if(l == null) System.exit(0);
			}
			int sum = nextInt();
			System.out.println((match(parse(), sum, 0))? "yes" : "no");
		}
	}
	
	static class Tree {
		int N;
		Tree left, right;
		
		public Tree(int N, Tree left, Tree right) {
			this.N = N;
			this.left = left;
			this.right = right;
		}
	}
}
