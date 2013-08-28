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

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

#ifdef L
#include "../../debug.h"
#endif


int main() {
    ios_base::sync_with_stdio(false);

    vector<int> fib(1000000, INF);

    fib[0] = 0, fib[1] = 1;
    int n, i;
    cin >> n;
    for(i = 2; ; i++) {
        fib[i] = fib[i-1] + fib[i-2];
        if(fib[i] > n) break;
    }

    int ix = lower_bound(ALL(fib), n) - fib.begin();

    if(fib[ix] == n) {
        cout << n << ' ' << 0 << ' ' << 0 << endl;
    } else {
        ix--;
        int iy = lower_bound(ALL(fib), n - fib[ix]) - fib.begin();
        if(fib[iy] == n - fib[ix]) {
            cout << fib[ix] << ' ' << fib[iy] << ' ' << 0 << endl;
        } else {
            iy--;
            int res = n - fib[ix];
            int iz = lower_bound(ALL(fib), res - fib[iy]) - fib.begin();
            if(fib[iz] == res - fib[iy]) {
                cout << fib[ix] << ' ' << fib[iy] << ' ' << fib[iz] << endl;
            } else {
                cout << "I'm too stupid to solve this problem" << endl;
            }
        }
    }
}

