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

const int maxn = 5000 + 10;

int s[maxn];

int main() {
    int t; scanf("%d", &t);

    while(t--) {
        int n; scanf("%d", &n);
        REP(i, 0, n) scanf("%d", &s[i]);
        sort(s, s+n);
        int ans = INF;

        REP(i, 1, n) ans = min(ans, s[i] - s[i-1]);

        printf("%d\n", ans);
    }
}

