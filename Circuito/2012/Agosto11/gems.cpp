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

//const int MAXN = (1<<24) + 10;

int a, b, c, n;
//int processed[MAXN];

inline int64 f(int64 v) {
    return (a * v * v + b * v + c) % n;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", &a, &b, &c, &n);

        //for(int i = 0; i < n; i++) processed[i] = -1;
        vector<int> processed(n, -1);

        int max_gems = -INF;
        for(int v = 0; v < n; v++) {
            if(processed[v] >= 0) continue;

            int u = v;
            int plen = 0;

            while(processed[u] == -1) {
                processed[u] = -2;
                u = f(u);
                plen++;
            }

            if(processed[u] >= 0) plen += processed[u];

            int clen = 0;
            while(processed[u] == -2) {
                processed[u] = -3;
                u = f(u);
                clen++;
            }

            u = v;
            while(processed[u] < 0) {
                if(processed[u] == -3) processed[u] = clen;
                if(processed[u] == -2) processed[u] = plen--;
                u = f(u);
            }
        }
        max_gems = *max_element(ALL(processed));
        printf("%d\n", max_gems);
    }
}

