import java.io.*;
import java.math.*;

public class c {
    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter output = new PrintWriter(System.out);

        String[] data = input.readLine().split(" ");
        int k, b, n, t;
        k = Integer.parseInt(data[0]);
        b = Integer.parseInt(data[1]);
        n = Integer.parseInt(data[2]);
        t = Integer.parseInt(data[3]);

        BigInteger x = BigInteger.ONE;

        for (int i = 0; i < n; i++) {
            x = x.multiply(new BigInteger(Integer.toString(k)));
            x = x.add(new BigInteger(Integer.toString(b)));
        }

        BigInteger z = x;

        x = new BigInteger(Integer.toString(t));
        long s = 0;

        for (int i = 0; i < n; i++) {
            if(x.compareTo(z) >= 0) break;
            x = x.multiply(new BigInteger(Integer.toString(k)));
            x = x.add(new BigInteger(Integer.toString(b)));
            s++;
        }

        output.println(s);

        output.close();
    }
}