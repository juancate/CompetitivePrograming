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
    int a, b, c;
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(ALL(v));
    a = v[0], b = v[1], c = v[2];

    long long ans = 0;

    while(a > 1) {
      ans += 2*(a+b+c) - 6;
      a--, b--, c--;
    }
    ans += b*c;

    cout << ans << endl;
    return 0;
}

