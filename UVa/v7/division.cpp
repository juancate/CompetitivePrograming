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

#ifdef DEBUG
#include "../../debug.h"
#endif

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int N;

bool differents(int x, int y) {
    int i = x, j = y;
    int cnt1 = 0, cnt2 = 0;
    bool digits[10] = {0}, zero = false;;

    while(x > 0) {
        int n = x % 10;
        if(n == 0) zero = true;
        if (digits[n]) return false;
        digits[n] = true;
        x /= 10;
        cnt1++;
    }

    while(y > 0) {
        int n = y % 10;
        if(n == 0) zero = true;
        if (digits[n]) return false;
        digits[n] = true;
        y /= 10;
        cnt2++;
    }

    if(cnt1 == cnt2 && cnt1 == 5) {
        printf("%d / %d = %d\n", i, j, N);
        return true;
    }
    if(cnt1 == 4 && !zero && cnt2 == 5) {
        printf("0%d / %d = %d\n", i, j, N);
        return true;
    }
    if(cnt2 == 4 && !zero && cnt1 == 5) {
        printf("%d / 0%d = %d\n", i, j, N);
        return true;
    }
    return false;
}

int main() {
    char line[100];
    int cases = 0;
    while(sscanf(gets(line), "%d", &N), N) {
        bool sol = false;
        if(cases++) puts("");
        for (int i = 1234; i * N <= 98765; i++) {
            int j = i * N;
            if (differents(j, i)) {
                sol = true;
            }
        }
        if(!sol) printf("There are no solutions for %d.\n", N);
    }
}

