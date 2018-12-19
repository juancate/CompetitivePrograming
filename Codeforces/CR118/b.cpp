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

bool comp(pair<int, double> a, pair<int, double> b) {
    if(fabs(a.second - b.second) < EPS) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, t1, t2, k;
    cin >> n >> t1 >> t2 >> k;
    
    double porcentage = k / 100.;
    vector< pair<int, double> > table(n);

    REP(i, 0, n) {
        int a, b;
        cin >> a >> b;
        double g1 = (a * t1) - (a * t1 * porcentage) + (b * t2);
        double g2 = (b * t1) - (b * t1 * porcentage) + (a * t2);

        double result = max(g1, g2);
        table[i] = make_pair(i+1, result);
    }
    sort(ALL(table), comp);

    cout << setprecision(2) << fixed;

    REP(i, 0, n) {
        cout << table[i].first << ' ' << table[i].second << '\n';
    }
}

