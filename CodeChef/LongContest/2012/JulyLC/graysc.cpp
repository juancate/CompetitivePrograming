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
typedef unsigned long long uint64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXN = 200;

uint64 numbers[MAXN];

int main() {
    int n;
    scanf("%d", &n);

    if(n > MAXN) {
        puts("Yes");
        return 0;
    }

    REP(i, 0, n) scanf("%llu", &numbers[i]);

    map<uint64, int> pairs;

    REP(i, 0, n) {
        REP(j, i+1, n)
            pairs[numbers[i] ^ numbers[j]] = i;
    }

    bool ok = false;

    REP(i, 0, n) {
        REP(j, i+1, n) {
            if(j < pairs[numbers[i] ^ numbers[j]]) {
                ok = true;
                break;
            }
        }
        if(ok) break;
    }

    puts(ok? "Yes" : "No");
}

