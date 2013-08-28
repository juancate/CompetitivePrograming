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

int sum_digits(int x) {
    int sum = 0;
    while(x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}


int main() {
    int a, b;
    while(scanf("%d%d", &a, &b) && a != -1 && b != -1) {
        int64 sum = 0;

        for(int i = a; i <= b; i++) {
            sum += sum_digits(i);
        }
        printf("%lld\n", sum);
    }
}

