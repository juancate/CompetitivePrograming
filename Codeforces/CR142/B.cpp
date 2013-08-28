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
#include <set>
#include <map>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

const int maxp = 1000010;
bool primes[maxp];

void sieve() {
    memset(primes, true, sizeof(primes));
    primes[0] = primes[1] = false;

    for(int64 i = 2; i < maxp; i++) {
        for(int64 j = i*i; j < maxp; j += i)
            primes[(int)j] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    sieve();

    int n; cin >> n;

    REP(i, 0, n) {
        int64 x; cin >> x;

        if(x == 1) {
            cout << "NO\n";
            continue;
        }

        int64 lo = (int64)sqrt((double)x);

        if(primes[lo] && lo * lo == x) cout << "YES\n";
        else cout << "NO\n";
    }
}

