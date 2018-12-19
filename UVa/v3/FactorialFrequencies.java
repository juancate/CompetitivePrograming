import java.util.*;
import java.io.*;
import java.math.*;

public class FactorialFrequencies {
    int[][] ans = new int[367][10];

    void digitcount(int i, char[] x) {
        for(char ch: x) {
            ans[i][ch - '0']++;
        }
    }

    void precalc() {
        BigInteger n = BigInteger.ONE;
        for(int i = 1; i <= 366; i++) {
            n = n.multiply(BigInteger.valueOf(i));
            digitcount(i, n.toString().toCharArray());
        }
    }

    void run() throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        precalc();
        String ln = in.readLine();
        while(ln != null && ln.length() > 0) {
            int n = Integer.parseInt(ln);
            if(n == 0) break;

            out.printf("%d! --\n", n);

            for(int i = 0; i < 10; i++) {
                if(i != 0 && i != 5) out.printf(" ");
                out.printf("   (%d) %4d", i, ans[n][i]);
                if(i == 4) out.println();
            }
            out.println();

            ln = in.readLine();
        }

        out.close();
    }

    public static void main(String[] args) {
        try {
            FactorialFrequencies obj = new FactorialFrequencies();
            obj.run();
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }
}
