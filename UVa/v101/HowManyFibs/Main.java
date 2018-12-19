import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {
  static ArrayList<BigInteger> fib = new ArrayList<BigInteger>();

  static String getLimit() {
    StringBuilder sb = new StringBuilder("1");

    for (int i = 0; i < 101; i++)
      sb.append("0");

    return sb.toString();
  }

  static void fibonacci() {
    fib.add(BigInteger.ZERO);
    fib.add(BigInteger.ONE);
    fib.add(BigInteger.valueOf(2));

    BigInteger limit = new BigInteger(getLimit());

    for (int i = 3; ; i++) {
      int last = fib.size();
      BigInteger fi = fib.get(last-1).add(fib.get(last-2));
      if (fi.compareTo(limit) > 0)
        break;
      fib.add(fi);
    }
  }

  public static void main (String[] args) throws Exception {
    BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter cout = new PrintWriter(System.out);

    fibonacci();

    while (true) {
      StringTokenizer stk = new StringTokenizer(cin.readLine());
      BigInteger a = new BigInteger(stk.nextToken());
      BigInteger b = new BigInteger(stk.nextToken());

      if (a.compareTo(BigInteger.ZERO) == 0 && b.compareTo(BigInteger.ZERO) == 0)
        break;

      int start = 0, end = 0;

      for (int i = 1; i < fib.size(); i++)
        if (fib.get(i).compareTo(a) >= 0) {
          start = i;
          break;
        }

      for (int i = fib.size()-1; i > 0; i --)
        if (fib.get(i).compareTo(b) <= 0) {
          end = i;
          break;
        }

      cout.println(end - start + 1);
    }

    cout.close();
  }
}
