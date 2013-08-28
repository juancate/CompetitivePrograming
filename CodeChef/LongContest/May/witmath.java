import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class witmath {

  static boolean isPrime(long n) {
    return BigInteger.valueOf(n).isProbablePrime(7);
  }

  public static void main(String[] args) throws Exception {
    BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter cout = new PrintWriter(System.out);

    int t = Integer.parseInt(cin.readLine());

    for(int run = 0; run < t; run++) {
      long n = Long.parseLong(cin.readLine());

      while(!isPrime(n))
        n--;

      cout.println(n);
    }

    cout.close();
  }
}
