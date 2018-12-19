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

const int maxn = 100010;

int64 s[maxn], pre[maxn], pos[maxn], n;

int main() {
    ios_base::sync_with_stdio(false);
    memset(s, 0, sizeof s);
    memset(pre, 0, sizeof pre);
    memset(pos, 0, sizeof pos);

    cin >> n;

    for(int i = 1; i <= n; i++)
      cin >> s[i];

    pre[1] = s[1];
    for(int i = 2; i <= n; i++) {
      pre[i] = s[i] ^ pre[i-1];
    }

    pos[n] = s[n];
    for(int i = n-1; i > 0; i--) {
      pos[i] = s[i] ^ pos[i+1];
    }

    int64 best = 0;
    for(int i = 0; i <= n; i++) {
      for(int j = i+1; j <= n+1; j++)
        best = max(best, pre[i] ^ pos[j]);
    }
    cout << best << endl;
}

