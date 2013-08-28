#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <cctype>
#include <vector>

#define foreach(it,v) for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

string to_lower(const string& str) {
    string s;
    for(int i = 0; i < (int)str.size(); i++) {
        s.push_back(tolower(str[i]));
    }
    return s;
}

vector<string> split(const string& str) {
    vector<string> v;
    for(int i = 0; i < (int)str.size(); i++) {
        int j = i;
        string s;
        while(j < (int)str.size() && isalpha(str[j])) {
            s.push_back(str[j++]);
        }
        if(s.empty()) continue;
        v.push_back(s);
        i = j;
    }
    return v;
}

int main(int argc, char *argv[])
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
#endif

    set<string> dictionary;
    string s;

    while(getline(cin, s)) {
        vector<string> v = split(s);
        foreach(w, v)
            dictionary.insert(to_lower(*w));
    }

    foreach(w, dictionary) cout << *w << endl;

    return 0;
}
