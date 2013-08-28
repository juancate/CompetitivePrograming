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

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXN = 1000000;

int limit;
int seq[MAXN];

int divisors(int p) {
    if(p == 1) return 1;

    int q = 2;
    int cnt = 1;
    while(q <= p / q) {
        while(p % q == 0) {
            cnt++;
            p /= q;
        }
        q++;
    }

    if(p != 1) cnt++;

    return cnt;
}

void generate() {
    limit = 0;
    seq[++limit] = 1;

    int prev = 1;

    while(prev < 20) {
        int d = divisors(prev);
        int val = prev + d;
        seq[++limit] = val;
        prev = val;
        printf("val = %d, d = %d\n", val, d);
    }
}

int main() {
    generate();
    for(int i = 0; i < limit; i++)
        printf("%d ", seq[i]);
    puts("");
}

