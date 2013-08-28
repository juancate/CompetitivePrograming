import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {
  static BigInteger toBin(BigInteger x) {
    BigInteger mask = x.shiftRight(1);

    while (mask.compareTo(BigInteger.ZERO) != 0) {
      x = x.xor(mask);
      mask = mask.shiftRight(1);
    }

    return x;
  }

  static BigInteger toGray(BigInteger x) {
    return x.xor(x.shiftRight(1));
  }

  static BigInteger getGreat(int n) {
    BigInteger x = BigInteger.ONE;
    return x.shiftLeft(n);
  }

  static String getAns(String s, int n) {
    StringBuffer sb = new StringBuffer();
    for (int i = 0; i < n-s.length(); i++)
      sb.append('0');
    sb.append(s);
    return sb.toString();
  }

  public static void main(String[] args) throws Exception {
    BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter cout = new PrintWriter(System.out);

    while (true) {
      StringTokenizer stk = new StringTokenizer(cin.readLine());
      int m = Integer.parseInt(stk.nextToken());
      String w = stk.nextToken();

      if (m == 0 && w.equals("0"))
        break;

      BigInteger x = new BigInteger(w, 2);
      x = toBin(x).add(BigInteger.valueOf(m));
      int n = w.length();

      BigInteger max = getGreat(n);
      x = x.mod(max);

      String ans = getAns(toGray(x).toString(2), n);
      cout.println(ans);
    }

    cout.close();
  }
}
