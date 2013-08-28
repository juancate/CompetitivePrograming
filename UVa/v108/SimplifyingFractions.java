import java.io.*;
import java.util.*;
import java.math.*;

public class SimplifyingFractions {
    BufferedReader cin;
    PrintWriter cout;

    public void run() throws IOException {
        cin = new BufferedReader(new InputStreamReader(System.in));
        cout = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int t = Integer.parseInt(cin.readLine());

        while(t-- > 0) {
            solve();
        }

        cout.close();
    }

    private void solve() throws IOException {
        String[] ln = cin.readLine().split(" ");
        BigInteger a = new BigInteger(ln[0]);
        BigInteger b = new BigInteger(ln[2]);

        BigInteger gcd = a.gcd(b);

        cout.print(a.divide(gcd));
        cout.print(" / ");
        cout.println(b.divide(gcd));
    }

    public static void main(String[] args) {
        try {
            SimplifyingFractions obj = new SimplifyingFractions();
            obj.run();
        }
        catch(Exception e) {

        }
    }
}