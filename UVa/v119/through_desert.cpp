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

int compareTo(double x, double y, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MAXN = 50+10;

int N;
int dist[MAXN], fuel[MAXN];
string event[MAXN];

char line[111];

bool can(double X) {
    int start = dist[0], goal = dist[N-1], f = fuel[0];
    double ini = X;
    int last_leak = 0, leak_cnt = 0;

    for(int i = 1; i < N; i++) {
        double spent = 0.0;
        if(leak_cnt > 0)
            spent = leak_cnt * (dist[i] - last_leak);
        double current = (f * (dist[i] - start) / 100.);

        if(X - current - spent < 0) return false;

        if(event[i] == "Fuel consumption") {
            X -= current;
            f = fuel[i];
            start = dist[i];
        }
        else if(event[i] == "Leak") {
            if(leak_cnt > 0)
                X -= (dist[i] - last_leak);
            last_leak = dist[i];
            leak_cnt++;
        }
        else if(event[i] == "Gas station") {
            X = ini;
            start = dist[i];
            last_leak = dist[i];
        }
        else if(event[i] == "Mechanic") {
            leak_cnt = 0;
            X -= spent;
        }
        else if(event[i] == "Goal") {
            X -= current;
            X -= spent;
        }
    }
    return compareTo(X, 0.0) >= 0;
}

double binary_search() {
    double lo = 0.0, hi = INF;

    //while(fabs(lo - hi) > EPS) {
    for(int i = 0; i < 300; i++) {
        double mid = (hi + lo) / 2.;

        if(can(mid)) hi = mid;
        else lo = mid;
    }
    return lo;
}

int main() {
    int a, b;
    while(true) {
        N = 0;
        string e;
        scanf("%d%s", &a, line);
        e = line;
        scanf("%s%d", line, &b);
        e += " ", e += line;

        if(e == "Fuel consumption" && (a|b) == 0)
            break;

        dist[N] = a, event[N] = e, fuel[N] = b;
        N++;

        while(e != "Goal") {
            a = b = 0;
            scanf("%d%s", &a, line);
            e = line;

            if(e == "Fuel" || e == "Gas") {
                scanf("%s", line);
                e += " ", e += line;
                if(e == "Fuel consumption") {
                    scanf("%d", &b);
                }
            }
            dist[N] = a, event[N] = e, fuel[N] = b;
            N++;
        }

        double ans = binary_search();
        printf("%.3lf\n", ans);
    }
}

