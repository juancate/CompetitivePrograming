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

bool m[101][101];
int row[101], col[101];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    while(cin >> n) {
        if(!n) break;

        memset(row, 0, n * sizeof(int));
        memset(col, 0, n * sizeof(int));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> m[i][j];
                if(m[i][j]) row[i]++, col[j]++;
            }
        }
        int odd_rows = 0, odd_cols = 0;
        for(int i = 0; i < n; i++) {
            if(row[i] & 1) odd_rows++;
            if(col[i] & 1) odd_cols++;
        }

        if(odd_rows == 0 && odd_cols == 0) {
            puts("OK");
            continue;
        }
        if(odd_rows > 1 || odd_cols > 1) {
            puts("Corrupt");
            continue;
        }
        int r = 0, c = 0;
        for(int i = 0; i < n; i++) if(row[i] & 1) r = i+1;
        for(int i = 0; i < n; i++) if(col[i] & 1) c = i+1;
        printf("Change bit (%d,%d)\n", r, c);
    }
    return 0;
}

