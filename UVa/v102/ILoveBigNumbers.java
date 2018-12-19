import java.util.*;
import java.io.*;
import java.math.*;

public class ILoveBigNumbers {
    int[] ans = new int[1001];

    int digitsum(char[] x) {
        int r = 0;
        for(char c : x) {
            r += c - '0';
        }
        return r;
    }

    void precalc() {
        ans[0] = ans[1] = 1;
        BigInteger n = BigInteger.ONE;
        for(int i = 2; i <= 1000; i++) {
            n = n.multiply(BigInteger.valueOf(i));
            ans[i] = digitsum(n.toString().toCharArray());
        }
    }

    void run() throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        precalc();
        String ln = in.readLine();
        while(ln != null && ln.length() > 0) {
            int n = Integer.parseInt(ln);

            out.println(ans[n]);
            ln = in.readLine();
        }

        out.close();
    }

    public static void main(String[] args) {
        try {
            ILoveBigNumbers obj = new ILoveBigNumbers();
            obj.run();
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }
}
