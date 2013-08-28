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
#include <set>
#include <map>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

vector<int> letters;

int main() {
    ios_base::sync_with_stdio(false);
    int k;
    string s;
    cin >> k >> s;

    int n = s.size();

    if(n % k) {
        cout << -1 << endl;
        return 0;
    }

    letters.assign(30, 0);

    REP(i, 0, n)
        letters[s[i] - 'a']++;

    vector<string> cnt;

    REP(i, 0, 30) {
        if(letters[i]) {
            cnt.push_back("");
            REP(j, 0, letters[i])
                cnt[cnt.size() - 1].push_back(i + 'a');
        }
    }

    vector<string> str(k, "");

    REP(i, 0, cnt.size()) {
        int a = cnt[i].size() / k;

        if(cnt[i].size() % k) {
            cout << -1 << endl;
            return 0;
        }

        REP(j, 0, k)
            str[j] += cnt[i].substr(0, a);
    }

    bool ok = true;
    int sum = (int)str[0].size();
    for(int i = 1; i < k && ok; i++) {
        if(str[i] != str[i-1]) {
            ok = false;
        }
        sum += (int)str[i].size();
    }
    if(!ok || sum != n) cout << -1 << endl;
    else {
        REP(i, 0, k)
            cout << str[i];
        cout << endl;
    }
}

