import java.io.*;
import java.util.*;
import java.math.*;

public class Fact500 {
    BigInteger[] fact = new BigInteger[1001];

    BufferedReader cin;
    PrintWriter cout;

    public void run() throws IOException {
        cin = new BufferedReader(new InputStreamReader(System.in));
        cout = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        fact[0] = fact[1] = BigInteger.ONE;

        for(int i = 2; i <= 1000; i++) {
            fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
        }
        String ln = cin.readLine();

        while(ln != null) {
            int n = Integer.parseInt(ln);

            cout.print(n);
            cout.println('!');
            cout.println(fact[n]);

            ln = cin.readLine();
        }

        cout.close();
    }

    public static void main(String[] args) {
        try {
            Fact500 obj = new Fact500();
            obj.run();
        } catch(IOException e) {

        }
    }
}