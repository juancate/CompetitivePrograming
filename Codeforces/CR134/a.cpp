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
    int n, k;
    cin >> n >> k;

    vector<int> points(2*n+1);

    REP(i, 0, 2*n+1) cin >> points[i];

    vector<int> ans = points;

    int cnt = 0;
    for(int i = 1; i < 2*n+1; i += 2) {
        if(cnt == k) break;

        int curr = points[i] - 1;
        if(i+1 < 2*n+1 && points[i-1] < curr && curr > points[i+1])
            ans[i]--, cnt++;
    }

    REP(i, 0, 2*n+1)
        cout << ans[i] << ' ';
    cout << endl;
}

