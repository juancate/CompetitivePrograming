import java.util.*;
import java.io.*;

public class JimmisRiddles {
  final String verbs = "(hate|love|know|like)s*";
  final String noun = "(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)";
  final String article = "(a|the)";
  final String actor = "(" + noun + "|" + article + " " + noun + ")";
  final String active_list = actor + "( and "+ actor + ")*";
  final String action = active_list + " " + verbs + " " + active_list;
  final String statement = action +"( , " + action +")*";

  public void run() throws IOException {
    BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter cout = new PrintWriter(System.out);

    String s;
    while((s = cin.readLine()) != null) {
      cout.println(s.replaceAll(" +", " ").trim().matches(statement)? "YES I WILL" : "NO I WON'T");
    }

    cout.close();
  }
  public static void main(String args[]) {
    try {
      new JimmisRiddles().run();
    } catch(IOException e) {
    }
  }
}
