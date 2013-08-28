import java.io.*;
import java.util.*;

public class c {
    public static void main(String[] args) {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter out = new PrintWriter(System.out);

            solve(in, out);

            out.close();
        } catch(IOException e) {

        }
    }

    static void solve(BufferedReader in, PrintWriter out) throw IOException {
        int n = Integer.parseInt(in.readLine());
        //for(int i = 0; i < n; i++) {
        build(in, null, n);
        //}
    }

    void build(BufferedReader in, Try p, int n) {
        String line = in.readLine();
        StringTokenizer stk = new StringTokenizer(line, " ,()");

        String op = stk.nextToken();
        if(op.equals("try")) {
            Try t = new Try(p);
            build(in, p, n-1);
        }

        line = in.readLine();
        stk = new StringTokenizer(line, " ,()");

        String act = stk.nextToken();
        while(act.equals("throw")) {
            String excp = stk.nextToken();
            line = in.readLine();
            stk = new StringTokenizer(line, " ,()");
            act = stk.nextToken();
            p.add_throw(excp);
        }

        while(act.equals("catch")) {
            String excp, msg;
            excp = stk.nextToken();
            msg = stk.nextToken();
            Catch c = new Catch(excp, msg);
            line = in.readLine();
            stk = new StringTokenizer(line, " ,()");
            act = stk.nextToken();
            p.add_catch(c);
        }

        op = act;
    }

    static class Catch {
        String type, message;
        public Catch(String t, String m) {
            type = t;
            message = m;
        }
    }

    static class Try {
        public Try p;
        public ArrayList<String> throw_list;
        public ArrayList<Catch> catch_list;

        public Try() {}
        public Try(Try parent) {
            p = parent;
            throw_list = new ArrayList<String>();
            catch_list = new ArrayList<String>();
        }

        public String check(String exc) {
            for(Catch c : catch_list) {
                if(c.type.equals(exc)) {
                    return c.type.message;
                }
            }
            return "Unhandled Exception";
        }

        public String check_all() {
            for(String t : throw_list) {
                String m = check(t);
                if(!m.equals("Unhandled Exception")) {
                    return m;
                }
            }

            Try x = p;
            while(x != null) {
                for(String t : throw_list) {
                    String m = p.check(t);
                    if(!m.equals("Unhandled Exception")) {
                        return m;
                    }
                }
                x = p.p;
            }
            return "Unhandled Exception";
        }

        public void add_throw(String t) {
            throw_list.add(t);
        }

        public void add_catch(Catch c) {
            catch_list.add(c);
        }
    }
}