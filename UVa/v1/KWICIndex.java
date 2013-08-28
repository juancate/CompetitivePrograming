import java.io.*;
import java.util.*;

public class KWICIndex {

    BufferedReader cin;
    PrintWriter cout;

    private void solve() throws IOException {
        String word = cin.readLine();

        Set<String> ignore_words = new TreeSet<String>();

        while(!word.equals("::")) {
            ignore_words.add(word);
            word = cin.readLine();
        }

        String phrase = cin.readLine();
        ArrayList<KWIC> final_list = new ArrayList<KWIC>();

        int k = 0;
        while(phrase != null) {
            String[] words = phrase.toLowerCase().split(" ");

            for(int i = 0; i < words.length; i++) {
                if(!ignore_words.contains(words[i])) {
                    StringBuffer sb = new StringBuffer();
                    for(int j = 0; j < words.length; j++) {
                        if(j > 0) {
                            sb.append(' ');
                        }
                        if(i == j) {
                            sb.append(words[j].toUpperCase());
                        }
                        else {
                            sb.append(words[j]);
                        }
                    }
                    KWIC current = new KWIC(sb.toString(), words[i].toUpperCase(), i, k);
                    final_list.add(current);
                }
            }

            phrase = cin.readLine();
            k++;
        }

        Collections.sort(final_list);

        for(KWIC p : final_list) {
            cout.println(p.phrase);
        }
    }

    static class KWIC implements Comparable<KWIC> {
        String phrase, key;
        int key_index, phrase_index;

        public KWIC(String phrase, String key, int key_index, int phrase_index) {
            this.phrase = phrase;
            this.key = key;
            this.key_index = key_index;
            this.phrase_index = phrase_index;
        }

        public int compareTo(KWIC o) {
            int sort = key.compareTo(o.key);

            if(sort == 0) {
                sort = Integer.valueOf(phrase_index).compareTo(o.phrase_index);
                if(sort == 0) {
                    sort = Integer.valueOf(key_index).compareTo(o.key_index);
                }
            }

            return sort;
        }
    }

    public void run() throws IOException {
        cin = new BufferedReader(new InputStreamReader(System.in));
        cout = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        solve();

        cout.close();
    }

    public static void main(String[] args) {
        try {
            KWICIndex obj = new KWICIndex();
            obj.run();
        }
        catch(Exception e) {
        }
    }
}