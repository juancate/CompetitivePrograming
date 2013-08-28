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

const int MOD = INF + 7;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    int64 f[] = {0, 0, 0, 1};

    REP(i, 0, n) {
        int64 fn[4] = {0};

        REP(j, 0, 4) {
            fn[j] = 0;
            REP(k, 0, 4) if(k != j) {
                fn[j] += f[k];
            }
            fn[j] %= MOD;
        }

        f[0] = fn[0], f[1] = fn[1], f[2] = fn[2], f[3] = fn[3];
    }
    cout << f[3] << endl;
}

