/*
ID: jcamarg1
LANG: JAVA
TASK: palsquare
*/

import java.io.*;
import java.util.*;

public class palsquare {
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
        BufferedReader f = new BufferedReader(new FileReader("palsquare.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("palsquare.out")));

        StringTokenizer st = new StringTokenizer(f.readLine());

        int B = Integer.parseInt(st.nextToken());

        for(int n = 1; n <= 300; n++) {
            int nn = n * n;
            char[] nnb = Integer.toString(nn, B).toUpperCase().toCharArray();

            if(is_palindrome(nnb)) {
                out.print(Integer.toString(n, B).toUpperCase());
                out.print(' ');
                out.println(nnb);
            }
        }

        out.close();
    }
}