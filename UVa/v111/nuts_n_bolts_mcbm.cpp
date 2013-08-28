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

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

typedef pair<int,int> ii;

const int MAXN = 1111;

int nuts, bolts, N, source, sink;
int parent[MAXN];
bool visited[511];
vector< vector<ii> > G;

int alternating_path(int left) {
    if(visited[left]) return 0;

    visited[left] = true;

    for(int j = 0; j < (int)G[left].size(); j++) {
        ii right = G[left][j];

        if(parent[right.first] == -1 || alternating_path(parent[right.first])) {
            parent[right.first] = left;
            return 1;
        }
    }

    return 0;
}

int main() {
    int t;
    scanf("%d", &t);

    for(int cases = 1; cases <= t; cases++) {
        scanf("%d%d", &bolts, &nuts);

        G.clear();
        N = nuts + bolts;
        G.resize(N);

        for(int i = 0; i < bolts; i++) {
            for(int j = 0; j < nuts; j++) {
                int x;
                scanf("%d", &x);
                if(x != 0) {
                    G[i].push_back( make_pair(j, x) );
                }
            }
        }

        int cardinality = 0;
        memset(parent, -1, sizeof(parent));

        for(int left = 0; left < bolts; left++) {
            memset(visited, false, sizeof(visited));
            cardinality += alternating_path(left);
        }

        printf("Case %d: ", cases);
        printf("a maximum of %d nuts and bolts ", cardinality);
        printf("can be fitted together\n");
    }
}

