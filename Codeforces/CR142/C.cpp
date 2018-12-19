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

const int maxn = 110;
const int maxm = 10010;

int dp[maxn][maxm], left_one[maxn][maxm], right_one[maxn][maxm], n, m;

int find_left(const string& s, int col) {
    if(s[col] == '1')
        return 0;

    int shifts = INF;

    for(int i = 1; i < m; i++) {
        int pos = (col - i + m) % m;

        if(s[pos] == '1') {
            shifts = min(shifts, i);
            break;
        }
    }

    return shifts;
}

int find_right(const string& s, int col) {
    if(s[col] == '1')
        return 0;

    int shifts = INF;

    for(int i = 1; i < m; i++) {
        int pos = (col + i) % m;
        if(s[pos] == '1') {
            shifts = min(shifts, i);
            break;
        }
    }

    return shifts;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    vector<string> board(n);

    REP(i, 0, n) {
        cin >> board[i];
        if(board[i].find("1") == string::npos) {
            cout << -1 << endl;
            return 0;
        }

        left_one[i][0] = find_left(board[i], 0);
        right_one[i][m-1] = find_right(board[i], m-1);

        REP(j, 1, m) {
            left_one[i][j] = (board[i][j] == '1')? 0 : left_one[i][j-1] + 1;
            right_one[i][m-1-j] = (board[i][m-1-j] == '1')? 0 : right_one[i][m-j] + 1;
        }
    }

    memset(dp, 0x3f, sizeof(dp));

    REP(i, 0, m) {
        dp[0][i] = min(left_one[0][i], right_one[0][i]);
    }

    REP(i, 1, n) {
        REP(j, 0, m) {
            dp[i][j] = min(left_one[i][j], right_one[i][j]);
            dp[i][j] += dp[i-1][j];
        }
    }

    int ans = INF;

    REP(j, 0, m) {
        ans = min(ans, dp[n-1][j]);
    }

    if(ans == INF) ans = -1;

    cout << ans << endl;
}

