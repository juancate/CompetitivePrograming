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

#define mp(x,y) make_pair(x, y)
typedef pair<int, int> ii;

int n, d, a, b;

bool cmp(pair<ii, int> p1, pair<ii, int> p2) {
    int m1 = p1.first.first * a + p1.first.second * b;
    int m2 = p2.first.first * a + p2.first.second * b;
    return m1 < m2;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> d >> a >> b;

    vector< pair<ii, int> > clients(n);
    REP(i, 0, n) {
        int l, h;
        cin >> l >> h;
        clients[i] = mp( mp(l, h), i+1 );
    }

    sort(ALL(clients), cmp);

    int cnt = 0;

    REP(i, 0, n) {
        int total = clients[i].first.first * a;
        total += clients[i].first.second * b;

        if(d - total < 0) break;
        d -= total;
        cnt++;
    }

    cout << cnt << endl;
    REP(i, 0, cnt) {
        if(i) cout << ' ';
        cout << clients[i].second;
    }
    cout << endl;
}

