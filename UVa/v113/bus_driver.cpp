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

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int morning[111], evening[111];

int main() {
    int n, d, r;

    while(~scanf("%d%d%d", &n, &d, &r) && (n|d|r) != 0) {
        for(int i = 0; i < n; i++) scanf("%d", &morning[i]);
        for(int i = 0; i < n; i++) scanf("%d", &evening[i]);

        sort(morning, morning + n);
        sort(evening, evening + n);

        int extra = 0;

        for(int i = 0; i < n; i++) {
            int time = morning[i] + evening[n - i - 1];
            if(time > d) extra += (time - d) * r;
        }

        printf("%d\n", extra);
    }
}

