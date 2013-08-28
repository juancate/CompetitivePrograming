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

vector<string> grid;
int dp[512][512];

string get(int n, int x, int y, const string& m) {
    string ret;
    ret.push_back(grid[x][y]);
    for(int i = 0; i < m.size(); i++) {
        switch(m[i]) {
            case 'N': x--; break;
            case 'S': x++; break;
            case 'W': y--; break;
            case 'E': y++;
        }
        ret.push_back(grid[x][y]);
    }
    return ret;
}

int solve(const string& f, const string& s) {
    memset(dp, 0, sizeof dp);
    int n = (int)f.size();
    int m = (int)s.size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(f[i] == s[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            }
            else {
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, w, h;
    cin >> t;

    for(int case_id = 1; case_id <= t; case_id++) {
        cin >> h >> w;
        grid.assign(h, "");
        for(int i = 0; i < h; i++)
            cin >> grid[i];

        int n, x0, y0;
        string moves;
        cin >> n >> x0 >> y0;
        cin.get();
        getline(cin, moves);
        x0--, y0--;

        string first = get(n, x0, y0, moves);

        cin >> n >> x0 >> y0;
        cin.get();
        getline(cin, moves);
        x0--, y0--;

        string second = get(n, x0, y0, moves);

        int ans = solve(first, second);

        printf("Case %d: %d %d\n", case_id, first.size() - ans, second.size() - ans);
    }
    return 0;
}

