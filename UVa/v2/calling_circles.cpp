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

int n, m, dfsNumberCounter, numSCC;
vector<int> G[32], dfs_num, dfs_low, S;
string names[32];
map<string, int> E;
vector< vector<int> > ans;
vector<bool> visited;

int get(const string& s) {
    if(!E.count(s)) {
        E[s] = E.size() - 1;
        names[E[s]] = s;
    }
    return E[s];
}

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;

    S.push_back(u);
    visited[u] = true;

    for(int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(dfs_num[v] < 0)
            tarjanSCC(v);
        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_low[u] == dfs_num[u]) {
        vector<int> curr;

        while(true) {
            int v = S.back();
            S.pop_back();
            visited[v] = false;
            curr.push_back(v);
            if(u == v) break;
        }

        ans.push_back(curr);
    }
}

void run_tarjan() {
    dfs_num.assign(n, -1);
    dfs_low.assign(n, 0);
    visited.assign(n, false);
    dfsNumberCounter = numSCC = 0;

    for(int i = 0; i < n; i++)
        if(dfs_num[i] < 0)
            tarjanSCC(i);
}

void print(int& case_id) {
    if(case_id) cout << "\n";
    cout << "Calling circles for data set " << ++case_id << ":\n";
    for(int i = 0; i < ans.size(); i++) {
        vector<int>& curr = ans[i];
        for(int j = 0; j < curr.size(); j++) {
            if(j) cout << ", ";
            cout << names[curr[j]];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int case_id = 0;
    while(cin >> n >> m) {
        if(!(n|m)) break;

        memset(G, 0, sizeof G);
        E.clear();
        ans.clear();

        for(int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;
            G[get(a)].push_back(get(b));
        }

        run_tarjan();
        print(case_id);
    }
    return 0;
}
