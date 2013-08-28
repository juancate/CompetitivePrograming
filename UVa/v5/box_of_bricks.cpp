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

int h[51];

int main() {
    int n, case_id = 1;
    while(scanf("%d", &n) && n) {
        int total = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &h[i]);
            total += h[i];
        }

        total /= n;

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(h[i] > total)
                ans += (h[i] - total);
        }
        printf("Set #%d\n", case_id++);
        printf("The minimum number of moves is %d.\n\n", ans);
    }
}

