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

int n, k, changes;
string ans;
bool end;

bool valid(string s) {
    REP(i, 1, n) {
        if(s[i] == s[i-1])
            return false;
    }
    return true;
}

void bckt(int at, int cnt, string s) {
    if(at == n-1) {
        if(valid(s)) {
            if(cnt < changes) {
                changes = cnt;
                ans = s;
            }
        }
        return;
    }

    char orig = s[at];

    for(int i = 0; i < k; i++) {
        string cp = s;
        cp[at] = 'A' + i;
        int current = cnt;

        if(i != orig - 'A')
            current++;
        bckt(at + 1, current, cp);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    string s;

    cin >> n >> k >> s;
    changes = INF;
    bckt(0, 0, s);

    cout << changes << endl;
    cout << ans << endl;
}

