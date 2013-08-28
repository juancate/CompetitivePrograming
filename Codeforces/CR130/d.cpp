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

typedef pair<int,int> prize;
#define cost first
#define id second

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<int> wraps(n);
    REP(i, 0, n) cin >> wraps[i];

    vector<prize> prizes(5);

    REP(i, 0, 5) {
        int x; cin >> x;
        prizes[i] = prize(x, i);
    }

    sort(ALL(prizes));

    int64 points = 0;
    vector<int64> cnt(5, 0);

    REP(i, 0, n) {
        points += wraps[i];
        int k = int(lower_bound(ALL(prizes), prize(points, INF)) - prizes.begin()) - 1;

        while(k >= 0 && prizes[k].cost <= points) {
            int total = points / prizes[k].cost;
            cnt[prizes[k].id] += total;
            points -= total * prizes[k].cost;
            k = int(lower_bound(ALL(prizes), prize(points, INF)) - prizes.begin()) - 1;
        }
    }
    REP(i, 0, 5) {
        if(i) cout << ' ';
        cout << cnt[i];
    }
    cout << endl << points << endl;
}

