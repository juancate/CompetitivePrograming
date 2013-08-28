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

typedef pair<int,int> ii;
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    map<int, int> front, total;

    REP(i, 0, n) {
        int a, b; cin >> a >> b;
        front[a]++;
        total[a]++;
        if(a != b) total[b]++;
    }

    int mid = (n + 1) / 2;

    int ans = INF;

    FOREACH(it, total) {
        int v = it->first;
        int cnt = it->second;

        int cnt_u = front[v];

        if(cnt >= mid) {
            if(cnt_u >= mid) {
                ans = 0;
            } else {
                ans = min(ans, mid - cnt_u);
            }
        }
    }

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}

