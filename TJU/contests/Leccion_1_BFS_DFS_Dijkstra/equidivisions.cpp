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
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int maxn = 100;

int board[maxn][maxn], n;
bool visited[maxn][maxn];

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool valid(int nr, int nc) {
    return (nr >= 0 && nr < n && nc >= 0 && nc < n);
}

int dfs(int i, int j, int parent) {
    if(visited[i][j]) return 0;

    visited[i][j] = true;

    int sum = 1;

    for(int k = 0; k < n; k++) {
        int nr = i + dr[k];
        int nc = j + dc[k];

        if(valid(nr, nc) && !visited[nr][nc]) {
            if(board[nr][nc] == parent)
                sum += dfs(nr, nc, parent);
        }
    }
    return sum;
}

int main() {
    while(scanf("%d", &n) && n) {
        fill(&board[0][0], &board[n][n], n);

        REP(i, 1, n) {
            REP(j, 0, n) {
                int a, b; scanf("%d%d", &a, &b);
                a--, b--;
                board[a][b] = i;
            }
        }

        memset(visited, false, sizeof(visited));

        bool good = true;

        for(int i = 0; i < n && good; i++) {
            for(int j = 0; j < n && good; j++) {
                if(!visited[i][j]) {
                    int s = dfs(i, j, board[i][j]);
                    if(s != n) {
                        good = false;
                    }
                }
            }
        }
        puts(good? "good" : "wrong");
    }
}

