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

bool board[8][8];
char m1[5], m2[5];

struct node {
    int r, c, cost;
    node(int row, int col, int cost_) {
        r = row, c = col, cost = cost_;
    }
};

int dr[] = {1, 2, -1, -2, 1, 2, -1, -2};
int dc[] = {2, 1, -2, -1, -2, -1, 2, 1};

bool valid(int nr, int nc) {
    return (nr >= 0 && nr < 8 && nc >= 0 && nc < 8);
}

int bfs(int row_start, int col_start, int row_end, int col_end) {
    memset(board, false, sizeof(board));

    queue< node > Q;
    Q.push( node(row_start, col_start, 0) );

    board[row_start][col_start] = true;

    while(!Q.empty()) {
        node current = Q.front();
        Q.pop();

        if(current.r == row_end && current.c == col_end)
            return current.cost;

        for(int k = 0; k < 8; k++) {
            int nr = current.r + dr[k];
            int nc = current.c + dc[k];

            if(valid(nr, nc) && !board[nr][nc]) {
                Q.push( node(nr, nc, current.cost + 1) );
                board[nr][nc] = true;
            }
        }
    }

    return -1;
}

int main() {
    while(~scanf("%s%s", m1, m2)) {
        int row_start = m1[0] - 'a';
        int col_start = m1[1] - '1';
        int row_end = m2[0] - 'a';
        int col_end = m2[1] - '1';

        printf("To get from %s to %s takes %d knight moves.\n",
               m1, m2, bfs(row_start, col_start, row_end, col_end));
    }
}

