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
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int b;
char number[100];

int64 tobase10() {
    int n = strlen(number);

    int64 p = 1, res = 0;

    for(int i = n-1; i >= 0; i--) {
        res += (number[i] - '0') * p;
        p *= b;
    }

    return res;
}

int sumdigits(int64 x) {
    int sum = 0;

    while(x > 0) {
        sum += (x % 10);
        x /= 10;
    }

    return sum;
}

int main() {
    while(scanf("%d", &b) && b) {
        scanf("%s", number);

        int64 val = tobase10();

        if((val % sumdigits(val)) == 0)
            puts("yes");
        else
            puts("no");
    }
}

