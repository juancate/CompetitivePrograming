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

const int maxn = 210*64*4;

bool G[210][4*64];
int pset[maxn], rank[maxn], H, W;

void init(int n) {
    for(int i = 0; i < n; i++) {
        pset[i] = i; rank[i] = 0;
    }
}

int find(int x) {
    return (pset[x] == x)? x : pset[x] = find(pset[x]);
}

void unite(int x, int y) {
    int px = find(x);
    int py = find(y);

    if(px == py)
        return;

    if(rank[px] < rank[py]) {
        pset[px] = py;
    }
    else {
        pset[py] = px;
        if(rank[px] == rank[py])
            rank[px]++;
    }
}

bool same_set(int x, int y) {
    return find(x) == find(y);
}

int get(int i, int j) {
    return i*(W+2) + j;
}

const string letters = "WAKJSD";
char ln[64];
string ans;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, -1, 0, 1};

void create_components() {
    init((H+2) * (W+2));

    for(int i = 0; i <= H+1; i++) {
        for(int j = 0; j <= W+1; j++) {
            for(int k = 0; k < 4; k++) {
                int r = i + dr[k];
                int c = j + dc[k];
                if(r < 0 || c < 0) continue;
                if(r > H+1 || c > W+1) continue;
                if(G[i][j] == G[r][c]) { // same component
                    unite(get(i,j), get(r,c));
                }
            }
        }
    }
}

void solve(int& case_id) {
    map<int, int> black;
    vector< set<int> > whites;

    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            for(int k = 0; k < 4; k++) {
                int r = i + dr[k];
                int c = j + dc[k];

                if(G[i][j] && !G[r][c]) {
                    int bid = find(get(i,j));
                    int wid = find(get(r,c));
                    int p;
                    if(!black.count(bid)) {
                        p = black[bid] = black.size()-1;
                        whites.push_back(set<int>());
                    }
                    else p = black[bid];
                    whites[p].insert(wid);
                }
            }
        }
    }

    ans = "";
    for(int i = 0; i < whites.size(); i++) {
        ans.push_back(letters[whites[i].size() - 1]);
    }
    sort(ans.begin(), ans.end());

    printf("Case %d: %s\n", case_id++, ans.c_str());
}

int main() {
    int case_id = 1;
    while(scanf("%d%d", &H, &W)) {
        if(!(H|W)) break;

        memset(G, 0, sizeof G);

        for(int i = 1; i <= H; i++) {
            scanf("%s", ln);
            for(int j = 0; j < W; j++) {
                int t = isdigit(ln[j])? ln[j]-'0' : ln[j]-'a'+10;
                for(int k = 0; k < 4; k++) {
                    G[i][4*j+k+1] = (t & (1 << (4-k-1)));
                }
            }
        }

        W *= 4;

        create_components();
        solve(case_id);
    }
}
