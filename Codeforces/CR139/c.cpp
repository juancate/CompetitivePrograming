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

const int maxn = 1010;

int rows, cols, x, y;
int white[maxn], black[maxn];

int rec(int color, int c) {
    if(c >= cols) {
        return 0;
    }

    int sum = 0;
    for(int i = 0; i < x && i+c < cols; i++) {
        sum += (color)? rows - black[i+c] : rows - white[i+c];
    }
    cerr << " c = " << c << " color = " << color << " sum = " << sum << endl;
    int ans = INF;

    for(int i = x+c; i <= y+c && i <= cols; i++) {
        //D(i+x+c);
        int current = sum + rec(color^1, i);
        D(current);
        ans = min(ans, current);
        D(ans);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

    memset(white, 0, sizeof(white));
    memset(black, 0, sizeof(black));

    cin >> rows >> cols >> x >> y;

    REP(i, 0, rows) {
        string line; cin >> line;
        REP(j, 0, cols) {
            if(line[j] == '#')
                black[j]++;
            else
                white[j]++;
        }
    }

    int ans = rec(1, 0);
    cout << ans << endl;
}

