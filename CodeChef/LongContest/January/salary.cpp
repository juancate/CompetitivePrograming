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

const int maxn = 100;

int s[maxn];

bool equals(int n) {
    for(int i = 1; i < n; i++)
        if(s[i] != s[i-1])
            return false;
    return true;
}

int main() {
    int t, n;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
            scanf("%d", &s[i]);

        int ans = 0;

        while(!equals(n)) {
            sort(s, s+n);
            int diff = s[n-1] - s[0];
            ans += diff;
            for(int i = 0; i < n-1; i++)
                s[i] += diff;
        }

        printf("%d\n", ans);
    }
    return 0;
}

