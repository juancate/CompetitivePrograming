import java.util.*;
import java.io.*;
import javax.script.*;

public class EnsuringTruth {
  public void run() throws Exception {
    ScriptEngineManager mgr = new ScriptEngineManager();
    ScriptEngine engine = mgr.getEngineByName("JavaScript");

    BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter cout = new PrintWriter(System.out);

    int t = Integer.parseInt(cin.readLine());
    while(t-->0) {
      String formula = cin.readLine();
      int n = formula.length();

      Map<Character,Boolean> dic = new HashMap<Character,Boolean>();
      boolean neg = false;
      for(int i = 0; i < n; i++) {
        char ch = formula.charAt(i);
        if(ch >= 'a' && ch <= 'z') {
          //if(neg) dic.put(ch, false);
          if(dic.get(ch) == null) dic.put(ch, true);
          neg = false;
        }
        else if(ch == '~') {
          neg = true;
        }
      }
      for(Map.Entry<Character,Boolean> e : dic.entrySet()) {
        formula = formula.replace(e.getKey()+"", e.getValue()+"");
      }
      boolean ans = Double.compare(Double.parseDouble(engine.eval(formula).toString()), 1.0) == 0;
      cout.println(ans? "YES" : "NO");
    }

    cout.close();
  }

  public static void main(String args[]) {
    try {
      new EnsuringTruth().run();
    } catch(Exception e) {
    }
  }
}
