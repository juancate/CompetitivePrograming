import java.io.*;
import java.math.*;

public class fctrl {

    static BufferedReader input;

    static int readInt() throws Exception {
        return Integer.parseInt(input.readLine());
    }

    public static void main(String[] args) throws Exception {
        input = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter output = new PrintWriter(System.out);

        int t = readInt();

        while(t-- > 0) {
            int n = readInt();
            int ans = 0;
            while(n > 0) {
                ans += n / 5;
                n /= 5;
            }
            output.println(ans);
        }

        output.close();
    }
}