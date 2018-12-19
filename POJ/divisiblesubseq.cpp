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

const int MAXN = 50000 + 10;
const int MAXD = 1000000 + 10;

int numbers[MAXN];
int64 sumseq[MAXN], cnt[MAXD];

int main() {
    int C, N, D;
    int64 ans;
    scanf("%d", &C);
    while (C--) {
        scanf("%d%d", &D, &N);
        sumseq[0] = 0;
        REP(i, 0, N) {
            scanf("%d", numbers + i);
            sumseq[i+1] = sumseq[i] + numbers[i];
        }

        memset(cnt, 0, D * sizeof(int64));
        
        ans = 0;
        REP(i, 0, N+1) {
            ans += cnt[sumseq[i] % D]++;
        }
        printf ("%d\n", ans);
    }
}

