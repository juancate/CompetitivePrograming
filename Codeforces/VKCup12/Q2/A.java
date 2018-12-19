import java.io.*;
import java.util.*;

public class A {

    static final int MAXN = 2000;
    static int[][] messages = new int[MAXN][MAXN];
    static boolean[][] visited = new boolean[MAXN][MAXN];

    static BufferedReader;
    static StringTokenizer _stk;

    static String readLine() {
        String l = input.readLine();
        if(l != null) _stk = new StringTokenizer(l, " ");
        return l;
    }

    static String next() { return _stk.nextToken(); }
    static int nextInt() { return Integer.parseInt(next()); }

    public static void main(String[] args) throws Exception {
        input = new BufferedReader(new InputStreamReader(System.in));
        readLine();
        int n = nextInt(), d = nextInt();
        HashMap<String, Integer> indices = new HashMap<String, Integer>();
    }
}