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

int n, k, m, ans, seq[20];

//check seq
bool check_seq() {
    for(int i = 0; i+k <= n; i++) {
        int max_b = *max_element(seq+i, seq+i+k);
        int cnt = count(seq+i, seq+i+k, max_b);
        if(cnt >= m) return false;
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d%d%d", &n, &k, &m);

        for(int i = 0; i < n; i++)
            scanf("%d", &seq[i]);

        if(m == 1) printf("-1\n");
        else {
            ans = INF;

            for(int subset = 0; subset < (1<<n); subset++) {
                for(int j = 0; j < n; j++) {
                    if(subset & (1 << j))
                        seq[j]++;
                }

                if(check_seq()) {
                    int curr = __builtin_popcount(subset);
                    ans = min(curr, ans);
                }

                for(int j = 0; j < n; j++) {
                    if(subset & (1 << j))
                        seq[j]--;
                }
            }

            if(ans == INF) ans = -1;
            printf("%d\n", ans);
        }
    }
}

