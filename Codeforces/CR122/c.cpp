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

const int MAXN = 50 + 10;

int n, m, cnt_sharp, cnt_visited;
char board[MAXN][MAXN];
bool visited[MAXN][MAXN];

int di[] = { 1, 0, -1, 0};
int dj[] = { 0, 1, 0, -1};

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int i, int j) {
    if(visited[i][j]) return;

    cnt_visited++;
    visited[i][j] = true;

    REP(k, 0, 4) {
        int ni = i + di[k];
        int nj = j + dj[k];

        if(valid(ni, nj) && board[ni][nj] == '#' && !visited[ni][nj])
            dfs(ni, nj);
    }
}

int calculate_visited(int i, int j) {
    memset(visited, false, sizeof(visited));

    cnt_visited = 0;

    REP(k, 0, 4) {
        int ni = i + di[k];
        int nj = j + dj[k];

        if(valid(ni, nj) && board[ni][nj] == '#' && !visited[ni][nj]) {
            dfs(ni, nj);
            break;
        }
    }

    return cnt_visited;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, 0, n) cin >> board[i];

    cnt_sharp = 0;
    REP(i, 0, n) REP(j, 0, m)
        if(board[i][j] == '#') cnt_sharp++;

    if(cnt_sharp <= 2) {
        cout << -1 << endl;
        return 0;
    }

    REP(i, 0, n) {
        REP(j, 0, m) if(board[i][j] == '#') {
            board[i][j] = '.';

            calculate_visited(i, j);

            if(cnt_visited < cnt_sharp - 1) {
                cout << 1 << endl;
                return 0;
            }

            board[i][j] = '#';
        }
    }
    cout << 2 << endl;

    return 0;
}

