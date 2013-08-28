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

vector< vector<int> > G;
vector<int> in_degree;
char a[111], b[111];

int main() {
    int n, case_id = 0;
    while(~scanf("%d", &n)) {

        G.clear();
        G.resize(n);
        in_degree.assign(n, 0);
        map<string, int> index;
        vector<string> names(n);

        REP(i, 0, n) {
            scanf("%s", a);
            index[a] = i;
            names[i] = a;
        }

        int m; scanf("%d", &m);
        REP(i, 0, m) {
            scanf("%s%s", a, b);
            in_degree[index[b]]++;
            G[index[a]].push_back(index[b]);
        }

        set<int> Q;
        vector<string> topolSort;
        map<string, bool> visited;

        REP(i, 0, n) {
            if(in_degree[i] == 0)
                Q.insert(i);
        }

        while(!Q.empty()) {
            int v = *Q.begin();
            Q.erase(Q.begin());

            topolSort.push_back(names[v]);

            FOREACH(u, G[v]) {
                in_degree[*u]--;
                if(in_degree[*u] == 0) {
                    Q.insert(*u);
                }
            }
        }

        printf("Case #%d: Dilbert should drink beverages in this order:", ++case_id);
        FOREACH(v, topolSort)
            printf(" %s", v->c_str());

        puts(".\n");
    }
}

