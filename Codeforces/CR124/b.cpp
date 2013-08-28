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

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

void reduce(int& p, int& q) {
    int x = __gcd(p, q);

    while(x != 1) {
        p /= x;
        q /= x;
        x = __gcd(p, q);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int dp, dq;
    cin >> dp >> dq;
    vector<int> P(dp+1), Q(dq+1);
    REP(i, 0, dp+1) cin >> P[i];
    REP(i, 0, dq+1) cin >> Q[i];

    int start_p = 0, start_q = 0;

    if(dp < dq) {
        cout << "0/1" << endl;
    }else if(dp > dq) {
        if(P[start_p] * Q[start_q] < 0) cout << "-";
        cout << "Infinity" << endl;
    } else {
        int a = P[start_p], b = Q[start_q];
        reduce(a, b);
        if(b < 0) a = -a, b = -b;
        cout << a << '/' << b << endl;
    }
}

