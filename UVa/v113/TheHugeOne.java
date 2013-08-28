import java.io.*;
import java.util.*;
import java.math.*;

public class TheHugeOne {
    public static void main(String[] args) {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter out = new PrintWriter(System.out);

            TheHugeOne obj = new TheHugeOne();
            obj.solve(in, out);

            out.close();
        } catch(IOException e) {

        }
    }

    public void solve(BufferedReader in, PrintWriter out) throws IOException {
        int n = Integer.parseInt(in.readLine());

        while(n-- > 0) {
            BigInteger M = new BigInteger(in.readLine());

            String[] ln = in.readLine().split(" ");

            int k = Integer.parseInt(ln[0]);

            BigInteger[] nums = new BigInteger[k];

            for(int i = 0; i < k; i++) {
                nums[i] = new BigInteger(ln[i+1]);
            }

            boolean ok = true;

            for(BigInteger x : nums) {
                if(M.mod(x).compareTo(BigInteger.ZERO) != 0) {
                    ok = false;
                    break;
                }
            }

            out.print(M);
            if(ok) out.println(" - Wonderful.");
            else out.println(" - Simple.");
        }
    }
}