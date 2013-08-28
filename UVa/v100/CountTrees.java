import java.io.*;
import java.util.*;
import java.math.*;

public class CountTrees {
    public static void main(String[] args) {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter out = new PrintWriter(System.out);

            CountTrees obj = new CountTrees();
            obj.solve(in, out);

            out.close();
        } catch(IOException e) {

        }
    }

    static final int MAXN = 303;

    public void solve(BufferedReader in, PrintWriter out) throws IOException {
        BigInteger[] fact = new BigInteger[MAXN+MAXN];
        BigInteger[] trees = new BigInteger[MAXN]; // catalan numbers

        fact[0] = fact[1] = BigInteger.ONE;
        for(int n = 2; n < MAXN+MAXN; n++)
            fact[n] = fact[n-1].multiply(new BigInteger(Integer.toString(n)));

        trees[0] = BigInteger.ONE;

        for(int n = 1; n < MAXN; n++) {
            /*
            int val = 2 * (2 * n + 1);
            val /= n + 2;

            trees[n+1] = trees[n].multiply(new BigInteger(Integer.toString(val)));
            */
            trees[n] = fact[n+n].divide(fact[n].multiply(fact[n].multiply(new BigInteger(Integer.toString(n+1)))));
            trees[n] = trees[n].multiply(fact[n]);
        }

        String ln = in.readLine();
        while(!ln.equals("0")) {
            int n = Integer.parseInt(ln);

            out.println(trees[n]);

            ln = in.readLine();
        }
    }
}