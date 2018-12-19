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

// Algorithm: Number theory - Sieve

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int maxp = 10001;

bitset<100000010> criba;

void sieve() {
    criba.set();
    criba[0] = criba[1] = false;

    for(int64 i = 2; i <= maxp; i++) {
        if(criba[i]) {
            for(int64 j = i*i; j < 100000010; j += i) {
                criba[j] = false;
            }
        }
    }
}

int main() {
    sieve();

    int n;
    while(~scanf("%d", &n)) {
        if(n <= 3 && n != 2) {
            printf("%d is not the sum of two primes!\n", n);
            continue;
        }

        if(n & 1) {
            if(criba[n-2]) {
                printf("%d is the sum of %d and %d.\n", n, 2, n-2);
            }
            else {
                printf("%d is not the sum of two primes!\n", n);
            }
            continue;
        }

        int k = n / 2 - 1;
        bool ok = false;

        while(k >= 3) {
            if(criba[k] && criba[n-k]) {
                printf("%d is the sum of %d and %d.\n", n, k, n-k);
                ok = true;
                break;
            }

            k--;
        }

        if(!ok)
            printf("%d is not the sum of two primes!\n", n);
  }
}

