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

int g[100][100];

int main() {
    int a, b, case_id = 0;
    while(true) {
        scanf("%d%d", &a, &b);
        if(!(a|b)) break;

        map<int, int> m;
        memset(g, 0x3f, sizeof g);

        while(a|b) {
            if(!m.count(a)) m[a] = m.size()-1;
            if(!m.count(b)) m[b] = m.size()-1;
            g[m[a]][m[b]] = 1;

            scanf("%d%d", &a, &b);
        }

        int n = m.size();
        for(int i = 0; i < n; i++)
            g[i][i] = 0;
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        int l = 0;
        int avg = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                avg += g[i][j];
                l++;
            }
        }
        double ans = (double)avg / (double)l;
        printf("Case %d: average length between pages = %.3lf clicks\n", ++case_id, ans);
    }
}

