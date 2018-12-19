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

const int maxn = 110, limit = 1000000;

int l[maxn], r[maxn], b[maxn], e[maxn], d[maxn], n, m;
bool used[limit+10];

bool is_overlapping() {
    memset(used, false, sizeof used);

    for(int i = 0; i < n; i++) {
        for(int j = l[i]; j < r[i]; j++) {
            if(used[j]) return true;
            else used[j] = true;
        }
    }

    for(int i = 0; i < m; i++) {
        int nb = b[i];
        int ne = e[i];

        while(nb <= limit) {
            for(int j = nb; j < min(limit, ne); j++) {
                if(used[j]) return true;
                else used[j] = true;
            }

            nb += d[i];
            ne += d[i];
        }
    }

    return false;
}

int main() {
    while(scanf("%d%d", &n, &m)) {
        if(!(n|m)) break;

        for(int i = 0; i < n; i++) {
            scanf("%d%d", &l[i], &r[i]);
        }

        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &b[i], &e[i], &d[i]);
        }

        puts(is_overlapping()? "CONFLICT" : "NO CONFLICT");
    }
}

