import java.io.*;
import java.util.*;
import java.math.*;

public class Overflow {
    BufferedReader cin;
    PrintWriter cout;

    final String first = "first number too big";
    final String second = "second number too big";
    final String result = "result too big";

    public void run() throws IOException {
        cin = new BufferedReader(new InputStreamReader(System.in));
        cout = new PrintWriter(System.out);

        String ln = cin.readLine();
        BigInteger max_int = new BigInteger(Integer.toString(Integer.MAX_VALUE));

        while(ln != null) {
            StringTokenizer stk = new StringTokenizer(ln);

            BigInteger a = new BigInteger(stk.nextToken());
            char op = stk.nextToken().charAt(0);
            BigInteger b = new BigInteger(stk.nextToken());

            cout.println(ln);

            if(a.compareTo(max_int) > 0)
                cout.println(first);
            if(b.compareTo(max_int) > 0)
                cout.println(second);

            BigInteger ret = (op == '+')? a.add(b) : a.multiply(b);

            if(ret.compareTo(max_int) > 0)
                cout.println(result);

            ln = cin.readLine();
        }

        cout.close();
    }

    public static void main(String[] args) {
        try {
            Overflow obj = new Overflow();
            obj.run();
        } catch(IOException e) {

        }
    }
}
