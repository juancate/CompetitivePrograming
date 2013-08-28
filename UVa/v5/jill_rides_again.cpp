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

int dist[20001];

int main() {
    int b, r, s, v;
    scanf("%d", &b);
    r = 1;

    while(b--) {
        scanf("%d", &s);
        dist[0] = 0;
        for(int i = 1; i < s; i++) {
            scanf("%d", &v);
            dist[i] = v;
        }

        int low, up, ans = -INF;

        int current_sum = 0;
        for(int j = 1, i = 0; j < s; j++) {
            current_sum += dist[j];

            if(current_sum > ans || (current_sum == ans && j-i > up-low)) {
                low = i+1, up = j+1;
                ans = current_sum;
            }

            if(current_sum < 0) {
                current_sum = 0;
                i = j;
            }
        }
        if(ans < 0) printf("Route %d has no nice parts\n", r);
        else printf("The nicest part of route %d is between stops %d and %d\n", r, low, up);
        r++;
    }
}

