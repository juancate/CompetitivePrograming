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

#include <tr1/unordered_map>

int n;
vector<int> G[201];
bool L[201], L2[201];

int dfs(int v) {
    int acum = 0, inv = 0;

    for(int i = 0; i < G[v].size(); i++) {
        acum += dfs(G[v][i]);
        if(L[G[v][i]]) inv++;
    }

    if(G[v].size() && inv < G[v].size())
        L[v] = true;

    return acum + L[v];
}

int main() {
    ios_base::sync_with_stdio(false);

    while(cin >> n) {
        if(!n) break;
        memset(G, 0, sizeof G);
        memset(L, false, sizeof L);

        std::tr1::unordered_map<string, int> m;
        string a, b;

        cin >> a;
        m[a] = 0;

        for(int i = 0; i < n-1; i++) {
            cin >> a >> b;
            if(!m.count(a)) m[a] = m.size()-1;
            if(!m.count(b)) m[b] = m.size()-1;

            G[m[b]].push_back(m[a]);
        }

        int total = dfs(0);

        memcpy(L2, L, sizeof L);
        bool unique = true;

        for(int i = 0; i < n; i++) {
            if(!L2[i]) {
                memset(L, false, sizeof L);
                L[i] = true;
                if(dfs(0) == total) {
                    unique = false;
                    break;
                }
            }
        }

        cout << (n-total) << (unique? " Yes\n" : " No\n");
    }
    return 0;
}
