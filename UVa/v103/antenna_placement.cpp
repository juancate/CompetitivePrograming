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

const int maxr = 50, maxc = 15;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int N, rows, cols, board[maxr][maxc];
vector< vector<int> > G;
int colors[maxr * maxc], parent[maxr * maxc];
bool visited[maxr * maxc];

char line[30];

int valid(int nr, int nc) {
    return nr >= 0 && nr <= rows-1 && nc >= 0 && nc <= cols-1;
}

void dfs(int u, int clr) {
    if(colors[u] > 0) return;

    colors[u] = clr;

    FOREACH(v, G[u])
        dfs(*v, 3-clr);
}

bool khun(int left) {
    if(visited[left]) return false;

    visited[left] = true;

    for(int j = 0; j < (int)G[left].size(); j++) {
        int v = G[left][j];

        if(parent[v] == -1 || khun(parent[v])) {
            parent[v] = left;
            return true;
        }
    }
    return false;
}

int runkhun() {
    int mcbm = 0;

    memset(parent, -1, sizeof(parent));

    for(int u = 0; u < N; u++) {
        if(colors[u] == 1) {
            memset(visited, false, sizeof(visited));
            mcbm += khun(u);
        }
    }

    return mcbm;
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &rows, &cols);

        N = 0;
        memset(board, -1, sizeof(board));

        REP(i, 0, rows) {
            scanf("%s", line);

            REP(j, 0, cols) {
                if(line[j] == '*')
                    board[i][j] = N++;
            }
        }

        G.assign(N, vector<int>());
        REP(i, 0, rows) {
            REP(j, 0, cols) {
                if(board[i][j] >= 0) {
                    REP(k, 0, 4) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];

                        if(valid(nr, nc) && board[nr][nc] >= 0) {
                            G[board[i][j]].push_back(board[nr][nc]);
                        }
                    }
                }
            }
        }

        memset(colors, 0, sizeof(colors));

        REP(i, 0, N) if(colors[i] == 0) {
            dfs(i, 1);
        }

        int pairs = runkhun();

        int ans = pairs + N - 2*pairs;

        printf("%d\n", ans);
    }
}

