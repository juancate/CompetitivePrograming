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
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;


int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        int n = (int)s.size();
        bool ok = true;

        for(int len = 1; len <= n && ok; len++) {
            for(int i = 0; i < n && ok; i++) {
                if(i + len > n) break;
                string w = s.substr(i, len);
                reverse(w.begin(), w.end());
                if(s.find(w) == string::npos)
                    ok = false;
            }
        }
        cout << (ok? "YES" : "NO") << endl;
    }
    return 0;
}

