import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {
  static int n, k;
  static BigInteger[][] memo = new BigInteger[180][2];

  static BigInteger solve(int index, int zero) {
    if (index == n)
      return BigInteger.ONE;

    if (memo[index][zero] != null)
      return memo[index][zero];

    BigInteger ret = BigInteger.ZERO;
    int start = (zero == 1 || index == 0)? 1 : 0;
    for (int i = start; i < k; i++)
      ret = ret.add(solve(index+1, (i == 0)? 1 : 0));
    return memo[index][zero] = ret;
  }

  public static void main(String[] args) throws Exception {
    BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter cout = new PrintWriter(System.out);

    n = Integer.parseInt(cin.readLine());
    k = Integer.parseInt(cin.readLine());

    cout.println(solve(0,0));
    cout.close();
  }
}
