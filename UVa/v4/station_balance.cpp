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

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

typedef vector<int> vi;

int main() {
    int C, S, id = 1;
    while(~scanf("%d%d", &C, &S)) {
        vi m(S);
        double A = 0.0;
        REP(i, 0, S) {
            scanf("%d", &m[i]);
            A += m[i];
        }
        A /= C;
        while(m.size() < 2 * C) m.push_back(0);

        sort(ALL(m));

        vector<vi> chambers(C);

        int ch = 0;

        for(int i = 0; i < C; i++) {
            chambers[ch].push_back(m[i]);
            chambers[ch].push_back(m[2*C - i - 1]);
            ch = (ch++) % C;
        }

        double imbalance = 0.0;

        printf("Set #%d\n", id++);

        for(int i = 0; i < C; i++) {
            printf("%2d:", i);

            double sum = 0.0;
            for(int j = 0; j < chambers[i].size(); j++) {
                if(chambers[i][j] == 0) continue;

                sum += chambers[i][j];
                printf(" %d", chambers[i][j]);
            }
            imbalance += abs(sum - A);
            puts("");
        }

        printf("IMBALANCE = %.5lf\n\n", imbalance);
    }
}

