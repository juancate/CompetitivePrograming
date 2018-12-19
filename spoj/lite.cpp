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

// Algorithm: Segment tree + Lazy propagation.

#define LEFT(x) (x << 1)
#define RIGHT(x) ((x << 1) + 1)

const int maxn = 100010;

struct node {
    int mid, val, b, e;
    bool upd;
} t[maxn << 2];

void init(int v, int left, int rigth) {
    t[v].b = left; t[v].e = rigth;
    t[v].mid = (t[v].b + t[v].e) >> 1;
    t[v].upd = false;

    if(t[v].b == t[v].e) {
        t[v].val = 0;
    }
    else {
        init(LEFT(v), left, t[v].mid);
        init(RIGHT(v), t[v].mid+1, rigth);
        t[v].val = t[LEFT(v)].val + t[RIGHT(v)].val;
    }
}

inline void set_update(int v) {
    if(!t[v].upd) t[v].upd = true;
    else t[v].upd = false;
}

void do_update(int v) {
    if(!t[v].upd) return;

    t[v].val = (t[v].e - t[v].b + 1) - t[v].val;

    set_update(LEFT(v));
    set_update(RIGHT(v));
    t[v].upd = false;
}

void update(int v, int l, int r) {
    if(l <= t[v].b && t[v].e <= r) // fits in the interval
        set_update(v);
    do_update(v);
    if(l > t[v].e || r < t[v].b) return;
    if(!(l <= t[v].b && t[v].e <= r)) {
        update(LEFT(v), l, r);
        update(RIGHT(v), l, r);
        t[v].val = t[LEFT(v)].val + t[RIGHT(v)].val;
    }
}

int query(int v, int l, int r) {
    int ans = 0;
    do_update(v);

    if(l > t[v].e || r < t[v].b) ans = 0;
    else if(l <= t[v].b && t[v].e <= r) ans = t[v].val;
    else {
        ans = query(LEFT(v), l, r) + query(RIGHT(v), l, r);
        t[v].val = t[LEFT(v)].val + t[RIGHT(v)].val;
    }

    return ans;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    init(1, 1, n);

    for(int i = 0; i < m; i++) {
        int cmd, l, r;
        scanf("%d%d%d", &cmd, &l, &r);

        if(cmd == 0) update(1, l, r); //update
        else printf("%d\n", query(1, l, r)); // query
    }
    return 0;
}

