import java.io.*;
import java.util.*;
import java.text.SimpleDateFormat;

public class Main {
  public static final String timeStart = " 00:00:00";

  public static void main(String[] args) throws Exception {
    BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter cout = new PrintWriter(System.out);

    SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");

    int n = Integer.parseInt(cin.readLine());

    while (n-->0) {
      StringTokenizer stk = new StringTokenizer(cin.readLine());
      String a = stk.nextToken() + timeStart;
      String b = stk.nextToken() + timeStart;

      Date d1 = format.parse(a);
      Date d2 = format.parse(b);

      if (d1.compareTo(d2) > 0) {
        Date x = d1;
        d1 = d2; d2 = x;
      }
      long diff = d2.getTime() - d1.getTime();
      diff = diff / (24 * 60 * 60 * 1000);
      cout.println(diff);
    }

    cout.close();
  }
}
