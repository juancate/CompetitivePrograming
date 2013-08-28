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

const int INF = 0x3f3f3f3f;
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int maxn = 55;

int g[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false);

    int p, r;
    int case_id = 0;
    while(cin >> p >> r) {
        if((p|r) == 0)
            break;

        map<string, int> people;
        memset(g, 0x3f, sizeof(g));

        REP(i, 0, r) {
            string a, b; cin >> a >> b;
            int x, y;

            if(!people.count(a))
                people[a] = people.size() - 1;

            if(!people.count(b))
                people[b] = people.size() - 1;

            x = people[a], y = people[b];
            g[x][y] = g[y][x] = 1;
        }

        for(int i = 0; i < p; i++)
            g[i][i] = 0;

        for(int k = 0; k < p; k++)
            for(int i = 0; i < p; i++)
                for(int j = 0; j < p; j++)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

        int ans = -1;
        bool connected = true;

        for(int i = 0; i < p && connected; i++) {
            for(int j = 0; j < p && connected; j++) {
                ans = max(ans, g[i][j]);
                if(g[i][j] == INF)
                    connected = false;
            }
        }

        cout << "Network " << ++case_id << ": ";
        if(!connected)
            cout << "DISCONNECTED";
        else
            cout << ans;
        cout << endl << endl;
    }
}

