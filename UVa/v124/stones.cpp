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

int fibo[18];
bool isfibo[1010];

int main() {
    fibo[0] = 0, fibo[1] = 1;
    memset(isfibo, false, sizeof(isfibo));

    for(int i = 2; i < 18; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
        isfibo[fibo[i]] = true;
    }

    int n;
    while(~scanf("%d", &n) && n) {
        if(!isfibo[n])
            puts("Alicia");
        else
            puts("Roberto");
    }
}

