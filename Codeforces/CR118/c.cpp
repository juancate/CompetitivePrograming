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

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

const int MOD = INF + 7;

int64 modpow(int64 a, int64 n) {
    int64 pot = 1;
    while(n > 0) {
        if(n & 1) pot = (pot * a) % MOD;
        a = (a * a) % MOD;
        n = n >> 1;
    }
    return pot;
}

int main() {
    ios_base::sync_with_stdio(false);
    int64 n;
    cin >> n;

    if(n == 0) {
        cout << 1 << endl;
        return 0;
    }

    int64 nn = modpow(2, n - 1);
    int64 nn2 = modpow(2, n);
    nn2 = (nn2 + 1) % MOD;
    int64 ans = nn * nn2;

    cout << (ans % MOD) << endl;
}

