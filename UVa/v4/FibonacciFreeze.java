import java.io.*;
import java.util.*;
import java.math.*;

public class FibonacciFreeze {
    BufferedReader cin;
    PrintWriter cout;

    BigInteger[] fibo = new BigInteger[5010];

    void precalc() {
        fibo[0] = BigInteger.ZERO;
        fibo[1] = BigInteger.ONE;

        for(int i = 2; i <= 5000; i++)
            fibo[i] = fibo[i-1].add(fibo[i-2]);
    }

    public void run() throws IOException {
        cin = new BufferedReader(new InputStreamReader(System.in));
        cout = new PrintWriter(System.out);

        precalc();
        String ln = cin.readLine();
        while(ln != null) {
            int n = Integer.parseInt(ln);
            cout.printf("The Fibonacci number for %d is %d\n",
                        n, fibo[n]);
            ln = cin.readLine();
        }

        cout.close();
    }

    public static void main(String[] args) {
        try {
            FibonacciFreeze obj = new FibonacciFreeze();
            obj.run();
        }
        catch(IOException e) {
        }
    }
}
