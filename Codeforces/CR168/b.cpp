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

char G[64][64];
int n, m;
bool visited[64][64];

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

bool valid(int nr, int nc) {
    return nr >= 0 && nr < n && nc >= 0 && nc < m  && G[nr][nc] == 'B';
}

void dfs(int r, int c, int pr = -1, int pc = -1, int d = -1, bool u = false) {
    visited[r][c] = true;

    for(int k = 0; k < 4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if(nr == pr && nc == pc) continue;

        if(valid(nr, nc)) {
            if(u && k == d) {
                dfs(nr, nc, r, c, d, true);
            }
            else if(!u) {
                if(d == -1) dfs(nr, nc, r, c, k);
                else if(d == k) dfs(nr, nc, r, c, k, u);
                else dfs(nr, nc, r, c, k, true);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> G[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(G[i][j] == 'B') {
                memset(visited, false, sizeof visited);
                dfs(i, j);

                for(int k = 0; k < n; k++) {
                    for(int l = 0; l < m; l++) {
                        if(G[k][l] == 'B' && !visited[k][l]) {
                            cout << "NO\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "YES\n";
    return 0;
}

