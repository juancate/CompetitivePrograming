import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {
  static int n, x, y;
  static char[][] board;

  static char[] getBinaryString(String s) {
    BigInteger x = new BigInteger(s);
    char[] b = x.toString(2).toCharArray();
    char[] c = new char[n*n];
    Arrays.fill(c, '0');

    for (int i = b.length-1, j = c.length-1; i >= 0; i--, j--)
      c[j] = b[i];

    return c;
  }

  static void createBoard(String s) {
    board = new char[n][n];
    char[] b = getBinaryString(s);
    for (int i = n-1, j = 0; i >= 0; i--, j+=n)
      board[i] = Arrays.copyOfRange(b, j, j+n);
  }

  static int turn_red(int d) {
    switch(d) {
      case 0: d = 1; break;
      case 1: d = 2; break;
      case 2: d = 3; break;
      case 3: d = 0; break;
    }
    return d;
  }

  static int turn_blue(int d) {
    switch(d) {
      case 0: d = 3; break;
      case 1: d = 0; break;
      case 2: d = 1; break;
      case 3: d = 2; break;
    }
    return d;
  }

  static boolean is_blue(int x, int y) {
    return board[y][x] == '0';
  }

  static int[] move(int[] a, int d) {
    switch(d) {
      case 0: a[1]--; break;
      case 1: a[0]++; break;
      case 2: a[1]++; break;
      case 3: a[0]--; break;
    }
    return a;
  }

  static boolean solve() {
    State curr = new State(x, y, 0);

    while (curr != null) {

      if (curr.x == n-1 && curr.y == 0)
        return true;

      if (is_blue(curr.x, curr.y)) {
        board[curr.y][curr.x] = '1';
        curr.d = turn_blue(curr.d);
      }
      else {
        board[curr.y][curr.x] = '0';
        curr.d = turn_red(curr.d);
      }
      int[] moves = new int[]{curr.x, curr.y};
      moves = move(moves, curr.d);
      curr.x = moves[0]; curr.y = moves[1];

      if (!(curr.x >= 0 && curr.x < n && curr.y >= 0 && curr.y < n))
        curr = null;
    }

    return false;
  }

  static class State {
    int x, y, d;
    State(int x, int y, int d) {
      this.x = x; this.y = y; this.d = d;
    }
  }

  public static void main(String[] args) throws Exception {
    BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter cout = new PrintWriter(System.out);

    for (String ln = cin.readLine(); !ln.equals("0 0 0 0"); ln = cin.readLine()) {
      StringTokenizer stk = new StringTokenizer(ln);

      n = Integer.parseInt(stk.nextToken());
      createBoard(stk.nextToken());
      x = Integer.parseInt(stk.nextToken())-1;
      y = n-Integer.parseInt(stk.nextToken());

      cout.println(solve()? "Yes" : "Kaputt!");
    }

    cout.close();
  }
}
