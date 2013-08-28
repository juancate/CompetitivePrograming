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

const int MAXN = 100000 + 10;

int cooking_time[MAXN], order[MAXN];

bool cmp(int i, int j) {
    return (cooking_time[i] == cooking_time[j])? i < j : cooking_time[i] < cooking_time[j];
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    REP(i, 0, n) {
        scanf("%d", &cooking_time[i]);
        order[i] = i;
    }

    sort(order, order + n, cmp);

    int ans = 0;

    REP(start, 0, n) {
        int end = start;
        while(end < n && cooking_time[order[end]] == cooking_time[order[start]])
            end++;

        int last = 0;
        REP(i, start, end) {
            if(order[i] >= last) {
                ans++;
                last = order[i] + k;
            }
        }

        start = end - 1;
    }

    printf("%d\n", ans);
}

