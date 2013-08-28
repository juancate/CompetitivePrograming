import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {
  static final int maxn = 55;

  static BigInteger[][] choose = new BigInteger[maxn][maxn];
  BigInteger[][] dp;
  int[] avail;

  public void run() throws IOException {
    BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter cout = new PrintWriter(System.out);
    StringTokenizer stk = null;

    while(true) {
      stk = new StringTokenizer(cin.readLine());
      int m = Integer.parseInt(stk.nextToken());
      int k = Integer.parseInt(stk.nextToken());

      if(m == 0 && k == 0)
        break;

      avail = new int[k];
      for(int i = 0; i < k; i++)
        avail[i] = Integer.parseInt(cin.readLine());

      dp = new BigInteger[k+1][m+1];
      for(int b = 1; b <= m; b++) {
        dp[k][b] = BigInteger.ZERO;
      }
      dp[k][0] = BigInteger.ONE;

      for(int i = k - 1; i >= 0; i--) {
        for(int b = 0; b <= m; b++) {
          dp[i][b] = dp[i+1][b];
          for(int n = 1; n <= avail[i] && b - n >= 0; n++) {
            for(int s = 1; s <= n; s++) {
              dp[i][b] = dp[i][b].add(dp[i+1][b-n].multiply(choose[b-n+1][s]).multiply(choose[n-1][s-1]));
            }
          }
        }
      }
      cout.println(dp[0][m]);
    }

    cout.close();
  }

  public static void main(String[] args) {
    choose[0][0] = BigInteger.ONE;

    for(int i = 0; i < maxn; i++) {
      for(int j = 0; j < maxn; j++) {
        if(i != 0 || j != 0) choose[i][j] = BigInteger.ZERO;
        if(i > 0) choose[i][j] = choose[i][j].add(choose[i-1][j]);
        if(i > 0 && j > 0) choose[i][j] = choose[i][j].add(choose[i-1][j-1]);
      }
    }

    try {
      new Main().run();
    }
    catch(IOException e) {
      e.printStackTrace();
    }
  }
}
