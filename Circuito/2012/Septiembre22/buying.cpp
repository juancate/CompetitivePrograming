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

const int maxm = 100010;

struct segment {
    int left, right;

    segment(int l = 0, int r = 0) {
        left = l, right = r;
    }

    bool operator<(const segment& a) const {
        if(left == a.left)
            return right > a.right;
        return left < a.left;
    }
} intervals[maxm];

int main() {
    int t; scanf("%d", &t);
    int n, m, d;

    while(t--) {
    //while(~scanf("%d%d%d", &n, &m, &d)) {
        scanf("%d%d%d", &n, &m, &d);
        n *= 10;

        for(int i = 0; i < m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            intervals[i] = segment(a, a + n);
        }

        sort(intervals, intervals + m);

        int left = n;
        int ans = 0, i = 0;

        while(left < d) {
            int right = -1;

            while(i < m && intervals[i].left <= left) {
                if(right == -1 || right < intervals[i].right) {
                    right = intervals[i].right;
                }
                i++;
            }

            if(right == -1)
                break;

            ans++;
            left = right;
        }

        if(left < d) {
            puts("-1");
        }
        else {
            printf("%d\n", ans);
        }
    }
}

