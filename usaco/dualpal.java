/*
ID: jcamarg1
LANG: JAVA
TASK: dualpal
*/

import java.io.*;
import java.util.*;

public class dualpal {
    static boolean is_palindrome(char[] num) {
        int i = 0, j = num.length - 1;

        while(i < j) {
            if(num[i] != num[j])
                return false;
            i++; j--;
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader f = new BufferedReader(new FileReader("dualpal.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("dualpal.out")));

        StringTokenizer st = new StringTokenizer(f.readLine());

        int N = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());

        int cnt = 0;
        for(int i = S+1; cnt < N; i++) {
            int base_count = 0;
            for(int base = 2; base <= 10 && base_count < 2; base++) {
                char[] num = Integer.toString(i, base).toCharArray();
                if(is_palindrome(num))
                    base_count++;
            }

            if(base_count == 2) {
                out.println(i);
                cnt++;
            }
        }

        out.close();
    }
}