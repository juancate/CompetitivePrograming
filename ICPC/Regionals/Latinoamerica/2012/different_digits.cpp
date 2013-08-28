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

bool repeats(int x) {
    vector<int> digits(10, 0);
    for(; x > 0; x /= 10)
        digits[x % 10]++;

    for(int i = 0; i < 10; i++)
        if(digits[i] > 1)
            return true;
    return false;
}

int differents[50001];

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
#endif
    differents[0] = 0; differents[1] = 1;

    for(int i = 2; i <= 5000; i++) {
        differents[i] = differents[i-1];
        if(!repeats(i))
            differents[i]++;
    }

    int n, m;
    while(cin >> n >> m) {
        cout << differents[m] - differents[n-1] << endl;
    }
}

