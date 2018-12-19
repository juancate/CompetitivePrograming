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


int main() {
    int a, b;
    while(~scanf("%d%d", &a, &b) && (a|b)) {
        int q = abs(b - a);
        int ans = 1;

        int p = 2;

        while(p <= q / p) {
            if(q % p == 0) {
                int cnt = 1;
                while(q % p == 0) {
                    cnt++;
                    q /= p;
                }
                ans *= cnt;
            }

            p++;
        }

        if(q != 1) ans *= 2; // prime

        printf("%d\n", ans);
    }
}

