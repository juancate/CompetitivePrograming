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
#include <set>
#include <map>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string a, b;

    cin >> n >> a >> b;

    double total = 0.0, cnt = 0.0;
    vector<double> sum(26, 0.0);

    for(int i = 0; i < n; i++) {
        sum[a[i] - 'A'] += i + 1;
        total += sum[b[i] - 'A'] * (n - i);
    }

    sum.assign(26, 0.0);
    for(int i = n - 1; i >= 0; i--) {
        total += sum[b[i] - 'A'] * (i + 1);
        sum[a[i] - 'A'] += n - i;
    }

    for(int i = 1; i <= n; i++) cnt += (int64)i * i;

    cout.precision(9);
    cout.setf(ios::fixed);
    cout << (total / cnt) << endl;
}

