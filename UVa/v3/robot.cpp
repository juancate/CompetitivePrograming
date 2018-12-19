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

int n, m;
char g[64][64], ori[16];
bool used[64][64][4];

struct state {
    int r, c, o, time;
    state(int nr = -1, int nc = -1, int no = -1, int t = 0) {
        r = nr;
        c = nc;
        o = no;
        time = t;
    }
};

inline bool valid(int nr, int nc) {
    return nr > 0 && nr < n && nc > 0 && nc < m;
}

inline int turn_left(int o) {
    return (o - 1 + 4) % 4;
}

inline int turn_right(int o) {
    return (o + 1 + 4) % 4;
}

inline bool move(int& r, int& c, int o, int t) {
    switch(o) {
        case 0: r -= t; break;
        case 1: c += t; break;
        case 2: r += t; break;
        case 3: c -= t;
    }

    return valid(r, c) && !used[r][c][o] && !g[r][c];
}

int bfs(int sr, int sc, int er, int ec, int o) {
    queue<state> Q;
    Q.push(state(sr, sc, o));

    while(!Q.empty()) {
        state curr = Q.front();
        Q.pop();

        if(curr.r == er && curr.c == ec) return curr.time;
        if(used[curr.r][curr.c][curr.o]) continue;

        used[curr.r][curr.c][curr.o] = true;

        int no = turn_left(curr.o);
        Q.push(state(curr.r, curr.c, no, curr.time + 1));
        no = turn_right(curr.o);
        Q.push(state(curr.r, curr.c, no, curr.time + 1));

        for(int i = 1; i <= 3; i++) {
            int nr = curr.r;
            int nc = curr.c;
            if(move(nr, nc, curr.o, i)) {
                Q.push(state(nr, nc, curr.o, curr.time + 1));
            }
            else break;
        }
    }

    return -1;
}

int main() {
    map<string, int> oris;
    oris["north"] = 0; oris["east"] = 1;
    oris["south"] = 2; oris["west"] = 3;

    while(scanf("%d%d", &n, &m)) {
        if(!(n|m)) break;
        memset(g, 0, sizeof g);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int x;
                scanf("%d", &x);
                if(!g[i][j]) g[i][j] = x;
                if(!g[i+1][j]) g[i+1][j] = x;
                if(!g[i][j+1]) g[i][j+1] = x;
                if(!g[i+1][j+1]) g[i+1][j+1] = x;
            }
        }

        int sr, sc, er, ec;
        scanf("%d%d%d%d%s", &sr, &sc, &er, &ec, ori);
        memset(used, false, sizeof used);
        int ans = bfs(sr, sc, er, ec, oris[ori]);
        printf("%d\n", ans);
    }

    return 0;
}

