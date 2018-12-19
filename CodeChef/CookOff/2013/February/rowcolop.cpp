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

const int maxn = 314160;

int row[maxn], col[maxn];
char s[50];

int main() {
    int n, q, x, y, r, c;
    scanf("%d%d", &n, &q);

    while(q--) {
        scanf("%s%d%d", s, &x, &y);
        if(s[0] == 'R') row[x] += y;
        else col[x] += y;
    }

    r = c = -1;
    for(int i = 1; i <= n; i++) {
        r = max(r, row[i]);
        c = max(c, col[i]);
    }

    printf("%d\n", r+c);

    return 0;
}

