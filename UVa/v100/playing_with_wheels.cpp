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

struct State {
    int s[4];
    int cost;
    State(int _s1 = 0, int _s2 = 0, int _s3 = 0, int _s4 = 0, int _c = 0) {
        s[0] = _s1; s[1] = _s2; s[2] = _s3; s[3] = _s4;
        cost = _c;
    }
};

int t1, t2, t3, t4;
bool visited[10][10][10][10];

inline bool finish(int s1, int s2, int s3, int s4) {
    return (s1 == t1 && s2 == t2 && s3 == t3 && s4 == t4);
}

void addnext(queue< State >& Q, const State& current, int i) {
    int s[4];
    for(int k = -1; k <= 1; k += 2) {
        s[0] = current.s[0]; s[1] = current.s[1];
        s[2] = current.s[2]; s[3] = current.s[3];
        s[i] = (s[i] + k + 10) % 10;

        if(!visited[s[0]][s[1]][s[2]][s[3]])
        {
            State next(s[0], s[1], s[2], s[3], current.cost + 1);
            Q.push(next);
            visited[next.s[0]][next.s[1]][next.s[2]][next.s[3]] = true;
        }
    }
}

int bfs(int s1, int s2, int s3, int s4) {
    queue< State > Q;

    Q.push( State(s1, s2, s3, s4) );
    visited[s1][s2][s3][s4] = true;

    while(!Q.empty()) {
        State current = Q.front();
        Q.pop();

        if(finish(current.s[0], current.s[1], current.s[2], current.s[3]))
            return current.cost;

        for(int i = 0; i < 4; i++) {
            addnext(Q, current, i);
        }
    }
    return -1;
}

int main() {
    int t; scanf("%d", &t);

    while(t--) {
        int s1, s2, s3, s4;
        scanf("%d%d%d%d", &s1, &s2, &s3, &s4);
        scanf("%d%d%d%d", &t1, &t2, &t3, &t4);

        int n; scanf("%d", &n);

        memset(visited, false, sizeof(visited));
        int f[4];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 4; j++)
                scanf("%d", &f[j]);
            visited[f[0]][f[1]][f[2]][f[3]] = true;
        }

        printf("%d\n", bfs(s1, s2, s3, s4));
    }
}

