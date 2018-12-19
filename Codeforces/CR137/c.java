import java.io.*;
import java.util.*;
import java.math.*;

public class c {

    BufferedReader in;
    PrintWriter out;

    public void run() throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    private void solve() throws IOException {
        String[] ln = in.readLine().split(" ");

        int n = Integer.parseInt(ln[0]);
        int m = Integer.parseInt(ln[1]);

        ln = in.readLine().split(" ");
        BigInteger first = new BigInteger(ln[0]);

        for(int i = 1; i < n; i++)
            first = first.gcd(new BigInteger(ln[i]));

        ln = in.readLine().split(" ");
        BigInteger second = new BigInteger(ln[0]);

        for(int i = 1; i < m; i++)
            second = second.gcd(new BigInteger(ln[i]));

        out.println("first = " + first + " second = " + second);

        BigInteger gcd = first.gcd(second);

        out.println(gcd);

        out.println("1 1");
        out.println(first.divide(gcd));
        out.println(second.divide(gcd));
    }

    public static void main(String[] args) throws IOException {
        c obj = new c();
        obj.run();
    }
}