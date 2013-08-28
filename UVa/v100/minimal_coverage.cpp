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

const int maxn = 100010;

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
} lines[maxn];

int m, n;

int main() {
    int t; scanf("%d", &t);

    while(t--) {
        scanf("%d", &m);

        n = 0;
        int l, r; scanf("%d%d", &l, &r);

        while((l|r) != 0) {
            lines[n++] = segment(l, r);
            scanf("%d%d", &l, &r);
        }

        sort(lines, lines + n);

        l = 0, r = 0;

        vector<segment> ans;

        int i = 0;

        while(l < m) {
            segment best(INF, INF);
            while(i < n && lines[i].left <= l) {
                if((best.left == INF && best.right == INF) ||
                   best.right < lines[i].right)
                    best = lines[i];
                i++;
            }

            if(best.left == INF && best.right == INF)
                break;
            ans.push_back(best);
            l = best.right;
        }

        if(l < m)
            puts("0");
        else {
            printf("%d\n", (int)ans.size());
            REP(i, 0, ans.size()) {
                printf("%d %d\n", ans[i].left, ans[i].right);
            }
        }

        if(t) puts("");
    }
}

