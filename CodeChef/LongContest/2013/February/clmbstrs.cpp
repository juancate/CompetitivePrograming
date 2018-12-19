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

const int mod = INF + 7;
int f[1000002];

int main() {
    f[0] = 0; f[1] = 1;
    for(int i = 2; i <= 1000001; i += 2) {
        f[i] = (f[i-1] + f[i-2]) % mod;
        f[i+1] = (f[i] + f[i-1]) % mod;
    }
    
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, g;
        scanf("%d%d", &n, &g);
        int ans = __builtin_popcount(f[n+1]);
        puts((ans == g)? "CORRECT" : "INCORRECT");
    }

    return 0;
}

