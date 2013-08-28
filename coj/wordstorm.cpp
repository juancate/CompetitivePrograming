#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(string w, string s) {
    vector<int> wc(26, 0), sc(26, 0);
    for(int i = 0; i < (int)w.size(); i++)
        wc[w[i]-'A']++;
    for(int i = 0; i < (int)s.size(); i++)
        sc[s[i]-'A']++;
    for(int i = 0; i < 26; i++) {
        if(!sc[i]) continue;
        if(sc[i] > wc[i])
            return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    string w;
    while(cin >> w) {
        int n;
        string s;
        cin >> n;

        while(n--) {
            cin >> s;

            if(s.size() >= 4 && check(w, s) && s.find(w[4]) != string::npos)
                cout << s << " is valid" << endl;
            else
                cout << s << " is invalid" << endl;
        }
    }
    return 0;
}
