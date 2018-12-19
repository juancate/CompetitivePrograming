#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <iostream>
#include <fstream>
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

const int maxn = 6;

int n;
vector<string> board;
vector< vector<bool> > visited;

const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };

bool valid(int nr, int nc) {
    return nr >= 0 && nr <= n-1 && nc >= 0 && nc <= n-1;
}

int dfs(int r, int c, int left, int right) {
    if(visited[r][c]) {
        if(left == right)
            return left+right;
        else
            return -INF;
    }

    visited[r][c] = true;

    int ans = -INF;

    for(int k = 0; k < 4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if(valid(nr, nc) && !visited[nr][nc] && board[nr][nc] == board[r][c]) {
            if(board[r][c] == '(')
                ans = max(ans, dfs(nr, nc, left+1, right));
            else
                ans = max(ans, dfs(nr, nc, left, right+1));
        }
    }

    if(board[r][c] == '(') {
        for(int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(valid(nr, nc) && !visited[nr][nc] && board[nr][nc] != board[r][c]) {
                ans = max(ans, dfs(nr, nc, left+1, right));
            }
        }
    }

    return ans;
}

int main() {
    ifstream in("hshoe.in");
    ofstream out("hshoe.out");

    in >> n;

    board.assign(n, "");
    visited.assign(n, vector<bool>(n, false));

    REP(i, 0, n)
        in >> board[i];

    if(board[0][0] == ')')
        out << 0 << '\n';
    else
        out << dfs(0, 0, 0, 0) << '\n';

    in.close();
    out.close();
}

