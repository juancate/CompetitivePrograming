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

int cnt[256];
char s[222];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; s[i]; i++) {
            cnt[s[i]]++;
        }
        int ans = 0;
        for(int i = 0; i < 256; i++)
            ans += (cnt[i] >> 1) + (cnt[i] & 1);
        printf("%d\n", ans);
    }
    return 0;
}

