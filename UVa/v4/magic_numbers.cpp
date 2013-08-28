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

int64 N;

bool differents(int64 x) {
    bool digits[10] = {0};

    while(x > 0) {
        int n = x % 10;
        if (digits[n]) return false;
        digits[n] = true;
        x /= 10;
    }

    return true;
}


int main() {
    char line[100];
    int t;
    sscanf(gets(line), "%d", &t);
    int cases = 0;
    while(t--) {
        scanf("%lld", &N);
        bool sol = false;
        if(cases++) puts("");
        for (int64 i = 1; i * N <= 9876543210; i++) {
            int64 j = i * N;
            //cerr << "j = " << j << " dj = " << differents(j) << endl;
            if (differents(i) && differents(j)) {
                printf("%lld / %lld = %lld\n", j, i, N);
            }
        }
    }
}

