import java.io.*;
import java.util.*;
import java.math.*;

public class Krakovia {
    BufferedReader cin;
    PrintWriter cout;

    public void run() throws IOException {
        cin = new BufferedReader(new InputStreamReader(System.in));
        cout = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        String[] ln = cin.readLine().split(" ");
        int n = Integer.parseInt(ln[0]);
        int f = Integer.parseInt(ln[1]);

        for(int case_id = 1; (n|f) != 0; case_id++) {
            solve(case_id, n, f);

            ln = cin.readLine().split(" ");
            n = Integer.parseInt(ln[0]);
            f = Integer.parseInt(ln[1]);
        }

        cout.close();
    }

    private void solve(int case_id, int n, int f) throws IOException {
        BigInteger sum = BigInteger.ZERO;
        BigInteger friends = BigInteger.valueOf(f);

        for(int i = 0; i < n; i++) {
            BigInteger v = new BigInteger(cin.readLine());
            sum = sum.add(v);
        }

        cout.println("Bill #" + case_id + " costs " + sum +
                     ": each friend should pay " + sum.divide(friends));
        cout.println();
    }

    public static void main(String[] args) {
        try {
            Krakovia obj = new Krakovia();
            obj.run();
        }
        catch(Exception e) {

        }
    }
}