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

/*
  Problem: 216 - Getting in Line
  Algorithm: DP + Bitmask - TSP, construct solution, start anywhere
*/


int n, caseid;
int x[10], y[10];
double dist[10][10], memo[10][1<<10];
pair<int, int> sol[10][1<<10];

double solve(int pc, int bitmask) {
    if(bitmask + 1 == 1 << n)
        return 0;

    if(memo[pc][bitmask] > -0.5)
        return memo[pc][bitmask];

    double ret = INFLL;

    for(int next = 0; next < n; next++) {
        if((bitmask & (1 << next)) == 0) {
            double cable = dist[pc][next] + solve(next, bitmask | (1 << next));

            if(cable < ret) {
                sol[pc][bitmask] = make_pair( next, bitmask | (1 << next) );
                ret = cable;
            }
        }
    }

    return memo[pc][bitmask] = ret;
}

int main() {
    caseid = 1;
    while(scanf("%d", &n) && n) {
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &x[i], &y[i]);
            for(int j = i-1; j >= 0; j--) {
                dist[i][j] = dist[j][i] = hypot(double(x[j] - x[i]), double(y[j] - y[i])) + 16.;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < (1 << n); j++) {
                memo[i][j] = -1.0;
                sol[i][j] = make_pair(0,0);
            }
        }

        double total = solve(0, 1);
        int min_total = 0;

        for(int i = 1; i < n; i++) {
            int cost = solve(i, (1 << i));
            if(cost < total) {
                total = cost;
                min_total = i;
            }
        }

        puts("**********************************************************");
        printf("Network #%d\n", caseid++);

        pair<int, int> start;
        for(int i = 0; i < (1<<n); i++) {
            if(sol[min_total][i] != make_pair(0,0)) {
                start = make_pair(min_total, i);
                break;
            }
        }

        int k = 0;
        total = 0.0;
        while(k < n-1) {
            pair<int, int> next = sol[start.first][start.second];
            int i = start.first, j = next.first;
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
                   x[i], y[i], x[j], y[j], dist[i][j]);
            total += dist[i][j];
            start = next;
            k++;
        }

        printf("Number of feet of cable required is %.2lf.\n", total);
    }
}

