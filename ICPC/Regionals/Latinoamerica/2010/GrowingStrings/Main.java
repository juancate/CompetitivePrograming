import java.io.*;
import java.util.*;

public class Main {
  public static final int maxn = 10010;
  public static final long p = 13331;

  char[][] s;
  int N;
  int[] len, dp;
  long[][] H;
  long[] P;
  Integer[] pos;

  List<Integer>[] g;

  Comparator<Integer> cmp_len = new Comparator<Integer>() {
    public int compare(Integer a, Integer b) {
      return Integer.signum(len[a]-len[b]);
    }
    public boolean equals(Object o) {
      return false;
    }
  };

  void hash(int i) {
    int n = len[i];
    H[i] = new long[n];
    for (int j = 0; j < n; j++) {
      H[i][j] = (s[i][j] - 'a' + 1) * P[j];
      if (j > 0) H[i][j] += H[i][j-1];
    }
  }

  long get_hash(int i, int l, int r) {
    return H[i][r] - (l > 0 ? H[i][l-1] : 0);
  }

  boolean can(int i, int j) {
    long h1 = get_hash(i, 0, len[i]-1);

    for (int k = 0; k + len[i] - 1 < len[j]; k++) {
      long h2 = get_hash(j, k, k+len[i]-1);
      if (h1 * P[k] == h2)
        return true;
    }
    return false;
  }

  int solve(int i) {
    if (dp[i] != -1)
      return dp[i];

    int r = 0;
    for (int j = g[i].size()-1; j >= 0; j--)
      r = Math.max(r, 1 + solve(g[i].get(j)));
    return dp[i] = r;
  }

  @SuppressWarnings("unchecked")
  public void solve() {
    Reader cin = new Reader();
    PrintWriter cout = new PrintWriter(System.out);

    P = new long[maxn];
    P[0] = 1;
    for (int i = 1; i < maxn; i++)
      P[i] = p * P[i-1];

    while (true) {
      N = cin.nextInt();
      if (N == 0)
        break;

      s = new char[N][];
      len = new int[N];
      pos = new Integer[N];
      H = new long[N][];

      for (int i = 0; i < N; i++) {
        s[i] = cin.next().toCharArray();
        len[i] = s[i].length;
        pos[i] = i;
        hash(i);
      }
      Arrays.sort(pos, cmp_len);

      g = new LinkedList[N];

      for (int i = 0; i < N; i++) {
        g[pos[i]] = new LinkedList<Integer>();
        for (int j = 0; j < i; j++) {
          if (len[pos[j]] >= len[pos[i]])
            break;
          if (can(pos[j], pos[i]))
            g[pos[i]].add(pos[j]);
        }
      }

      int ans = 0;
      dp = new int[N];
      Arrays.fill(dp, -1);

      for (int i = 0; i < N; i++)
        ans = Math.max(ans, 1 + solve(pos[i]));
      cout.println(ans);
    }

    cout.close();
  }

  public static void main (String[] args) {
    new Main().solve();
  }
}

class Reader {
  BufferedReader cin;
  StringTokenizer stk;

  public Reader() {
    cin = new BufferedReader(new InputStreamReader(System.in));
  }
  public String readln() {
    try { return cin.readLine(); } catch (Exception e) { }
    return null;
  }
  public String next() {
    if (stk == null || !stk.hasMoreTokens()) stk = new StringTokenizer(readln());
    return stk.nextToken();
  }
  public int nextInt() { return Integer.parseInt(next()); }
}


