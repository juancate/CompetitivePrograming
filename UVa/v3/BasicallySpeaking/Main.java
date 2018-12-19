import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception {
    BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter cout = new PrintWriter(System.out);

    for (String ln = cin.readLine(); ln != null; ln = cin.readLine()) {
      StringTokenizer stk = new StringTokenizer(ln);
      String number = stk.nextToken();
      int from = Integer.parseInt(stk.nextToken());
      int to = Integer.parseInt(stk.nextToken());

      int n = Integer.parseInt(number, from);
      String ans = Integer.toString(n, to);

      if (ans.length() > 7)
        ans = "ERROR";
      cout.printf("%7s\n", ans.toUpperCase());
    }

    cout.close();
  }
}
