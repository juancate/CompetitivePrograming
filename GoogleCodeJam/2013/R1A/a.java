import java.io.*;
import java.util.*;
import java.math.*;

public class a {

  static final BigInteger two = BigInteger.valueOf(2);
  static final BigInteger three = BigInteger.valueOf(3);

  static boolean check(long val, long t, long rad) {
    BigInteger x = BigInteger.valueOf(val);
    BigInteger r = BigInteger.valueOf(rad);

    // a = 2*r*x + 3*x + 2*x*x + 2*r + 1
    BigInteger a = r.multiply(x).multiply(two)
                    .add(x.multiply(three))
                    .add(x.multiply(x).multiply(two))
                    .add(r.multiply(two))
                    .add(BigInteger.ONE);

    int compare = a.compareTo(BigInteger.valueOf(t));

    return compare > 0;
  }

  public static void main(String[] args) {
    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();

    for(int run = 1; run <= T; run++) {
      long r, t;
      r = cin.nextLong();
      t = cin.nextLong();

      long lo = 0, hi = (long)1e9;

      while(lo < hi) {
        long mid = lo + (hi-lo) / 2;

        if(check(mid, t, r)) hi = mid;
        else lo = mid+1;
      }

      System.out.printf("Case #%d: %d\n", run, lo);
    }
  }
}
