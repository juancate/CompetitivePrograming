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

int indegree[210];

int main() {
    int n, m, a, b, i;
    bool tour;
    while(scanf("%d%d", &n, &m) != EOF) {
        memset(indegree, 0, n * sizeof(int));

        while(m--) {
            scanf("%d%d", &a, &b);
            indegree[a]++;
            indegree[b]++;
        }

        tour = true;

        for(int i = 0; i < n; i++) {
            if(!indegree[i] || indegree[i] & 1) {
                tour = false;
                break;
            }
        }

        puts(tour? "Possible" : "Not Possible");
    }
    return 0;
}

