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

#define D(x) cerr << #x " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;
const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXN = 500 + 10;

int data[MAXN], ans[MAXN];

int main(int argc, char *argv[]) {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int N;
    while(~scanf("%d", &N) && N) {
        REP(i, 0, N) {
            scanf("%d", data + i);
            ans[i] = 0;
        }

        REP(i, 0, N) {
            int cnt = data[i];
            REP(j, 0, N) {
                if(ans[j]) continue;
                if(cnt == 0) {
                    ans[j] = (i+1);
                    break;
                }
                if(ans[j] == 0) cnt--;
            }
        }

        REP(i, 0, N) {
            if(i) printf(",");
            printf("%d", ans[i]);
        }
        puts("");
    }

    return 0;
}
