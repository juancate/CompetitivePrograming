import java.io.*;
import java.util.*;
import java.math.*;

public class hexadecimal {
    BufferedReader in;
    PrintWriter out;

    public void run() throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        solve();

        out.close();
    }

    private void solve() throws IOException {
        String ln;
        while((ln = in.readLine()) != null) {
            BigInteger n = new BigInteger(ln, 16);
            out.println(n.toString(8));
        }
    }

    public static void main(String args[]) {
        try {
            hexadecimal obj = new hexadecimal();
            obj.run();
        } catch(IOException e) {

        }
    }
}