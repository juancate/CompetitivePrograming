#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const string alpha = "the quick brown fox jumps over the lazy dog";

char code['z'-'a'+1];

bool decrypt(string s) {
    REP(i, 0, s.size()) {
        if(s[i] == ' ' && alpha[i] == ' ')
            continue;

        if(s[i] == ' ' && alpha[i] != ' ') return false;
        if(s[i] != ' ' && alpha[i] == ' ') return false;

        if(code[s[i] - 'a'] != alpha[i])
            if(code[s[i] - 'a'] != 0)
                return false;
        code[s[i] - 'a'] = alpha[i];
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);

    int t; cin >> t; cin.get();

    string ln;
    getline(cin, ln);

    while(t--) {
        bool solution = false;
        vector<string> words;

        int cnt = 0;
        memset(code, 0, sizeof(code));

        while(getline(cin, ln)) {
            if(ln.size() == 0 && cnt > 0) break;

            words.push_back(ln);
            cnt++;

            if(ln.size() == alpha.size() && !solution) {
                if(ln == alpha) {
                    REP(i, 0, ln.size()) {
                        if(ln[i] == ' ')
                            continue;
                        code[ln[i] - 'a'] = ln[i];
                    }
                    solution = true;
                }
                else if(!decrypt(ln)) {
                    memset(code, 0, sizeof(code));
                } else {
                    solution = true;
                }
            }
        }


        bool ok = true;
        for(int i = 0; i < 'z'-'a' && ok; i++) {
            if(code[i] == 0)
                ok = false;
        }

        if(!ok) {
            cout << "No solution." << endl;
            if(t) cout << endl;
            continue;
        }

        for(int i = 0; i < words.size(); i++) {
            string s;
            s.assign(words[i].size(), ' ');
            for(int j = 0; j < words[i].size(); j++) {
                if(words[i][j] == ' ') continue;

                s[j] = code[words[i][j] - 'a'];
            }
            cout << s << endl;
        }
        if(t) cout << endl;
    }
}

