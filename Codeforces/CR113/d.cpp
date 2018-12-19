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

typedef pair<int,int> ii;
#define mp make_pair

const int MAXN = (int)1e5 + 5;

int N;
vector<int> parent;
vector<bool> visited;
vector< vector<ii> > G;

struct obj {
    int cost, size, num;
    obj(int c = 0, int s = 0, int n = 0) : cost(c), size(s), num(n) {}
};

bool cmp_size(const obj& a, const obj& b) {
    return a.size < b.size;
}

bool cmp_price(const obj& a, const obj& b) {
    return a.cost > b.cost;
}

int khun(int left) {
    if(visited[left]) return 0;

    visited[left] = true;

    for(int j = 0; j < (int)G[left].size(); j++) {
        ii right = G[left][j];

        if(parent[right.first] == -1 || khun(parent[right.first])) {
            parent[right.first] = left;
            return 1;
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n;

    vector<obj> shoes;
    vector<int> cost(n);

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        shoes.push_back(obj(a, b, i));
        cost[i] = a;
    }

    sort(ALL(shoes), cmp_size);

    cin >> m;

    vector<obj> people;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        people.push_back(obj(a, b, i));
    }

    N = m + n;

    G.resize(N);

    for(int i = 0; i < m; i++) {
        int j = int(lower_bound(ALL(shoes), obj(-1, people[i].size,-1), cmp_size) - shoes.begin());

        while(shoes[j].size == people[i].size || shoes[j].size - 1 == people[i].size) {
            if(shoes[j].cost <= people[i].cost)
                G[shoes[j].num].push_back(mp(people[i].num, shoes[j].cost));
            j++;
        }
    }

    sort(ALL(shoes), cmp_price);

    int64 profit = 0;
    parent.resize(N, -1);
    visited.resize(N);

    for(int left = 0; left < n; left++) {
        visited.assign(n, false);
        khun(shoes[left].num);
    }

    vector<ii> ans;

    for(int i = 0; i < N; i++) {
        if(parent[i] != -1) {
            profit += cost[parent[i]];
            ans.push_back(mp(i+1, parent[i]+1));
        }
    }

    cout << profit << endl;
    cout << ans.size() << endl;

    for(int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
}

