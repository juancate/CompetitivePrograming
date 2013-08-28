import java.io.*;
import java.util.*;

public class b {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int t = Integer.parseInt(cin.nextLine());
        for(int case_id = 1; case_id <= t; case_id++) {
            String s = cin.nextLine();
            s = s.replaceAll("\\(:\\)", "");
            s = s.replaceAll(":\\(", "");
            s = s.replaceAll(":\\)", "");
            s = s.replaceAll("\\(\\)", "");
            s = s.replaceAll("[a-z]", "");
            s = s.replaceAll(":", "");
            s = s.trim();
            System.out.printf("Case #%d: ", case_id);
            System.out.println((s.length() == 0)? "YES" : "NO");
        }
    }
}
