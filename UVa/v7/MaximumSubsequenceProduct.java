import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class MaximumSubsequenceProduct {
    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter output = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        BigInteger[] prod = new BigInteger[111];
        int[] data = new int[111];

        String line;
        while((line = input.readLine()) != null) {
            StringTokenizer stk = new StringTokenizer(line, " ");
            int n = 0;
            prod[0] = BigInteger.ONE;
            data[0] = 1;

            while(stk.hasMoreTokens()) {
                data[n+1] = Integer.parseInt(stk.nextToken());
                if(data[n+1] == -999999) break;
                prod[n+1] = prod[n].multiply(new BigInteger(Integer.toString(data[n+1])));
                n++;
                //output.println(data[n]);
                if(!stk.hasMoreTokens()) {
                    line = input.readLine();
                    if(line != null) stk = new StringTokenizer(line, " ");
                }
            }

            BigInteger max_prod = new BigInteger(Integer.toString(-100000));

            for(int i = 1; i <= n; i++) {
                BigInteger current_prod = BigInteger.ONE;
                for(int j = 0; j < i; j++) {
                    if(prod[j].compareTo(BigInteger.ZERO) == 0)
                        current_prod = new BigInteger(Integer.toString(data[i]));
                    else current_prod = prod[i].divide(prod[j]);
                    max_prod = max_prod.max(current_prod);
                }
            }
            output.println(max_prod);
        }
        output.close();
    }
}