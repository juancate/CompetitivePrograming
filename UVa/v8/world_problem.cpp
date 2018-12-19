#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int dict[1010][26], puzzle[26];

int main() {
    ios_base::sync_with_stdio(false);

    string w;
    int n = 0;
    memset(dict, 0, sizeof dict);

    while(getline(cin, w)) {
        if(w == "#")
            break;

        for(int i = 0; i < (int)w.size(); i++)
            dict[n][w[i]-'a']++;
        n++;
    }

    while(getline(cin, w)) {
        if(w == "#")
            break;

        int ans = 0;
        memset(puzzle, 0, sizeof puzzle);

        for(int i = 0; i < (int)w.size(); i++) {
            if(w[i] == ' ') continue;
            puzzle[w[i]-'a']++;
        }

        for(int i = 0; i < n; i++) {
            bool ok = true;
            for(int j = 0; j < 26; j++) {
                if(puzzle[j] < dict[i][j]) {
                    ok = false;
                    break;
                }
            }
            if(ok) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
