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

const int maxn = 1024010;

struct node {
    int mid, val, b, e;
    char upd;
} t[maxn << 2];

char s[55];
int a[maxn];

void init(int v, int left, int rigth) {
    t[v].b = left; t[v].e = rigth;
    t[v].mid = (t[v].b + t[v].e) >> 1;
    t[v].upd = ' ';

    if(t[v].b == t[v].e) {
        t[v].val = a[left];
    }
    else {
        init(LEFT(v), left, t[v].mid);
        init(RIGHT(v), t[v].mid+1, rigth);
        t[v].val = t[LEFT(v)].val + t[RIGHT(v)].val;
    }
}

// set for later update
void set_update(int v, char type) {
    if(type == 'I') {
        switch(t[v].upd) {
            case 'I': t[v].upd = ' '; break; // no upd need
            case ' ': t[v].upd = 'I'; break;
            case 'F': t[v].upd = 'E'; break;
            case 'E': t[v].upd = 'F'; break;
        }
    } else {
        t[v].upd = type;
    }
}

// propagate the update
void do_update(int v) {
    if(t[v].upd == ' ') return;

    switch(t[v].upd) {
        case 'E': t[v].val = 0; break;
        case 'F': t[v].val = t[v].e - t[v].b + 1; break;
        case 'I': t[v].val = (t[v].e - t[v].b + 1) - t[v].val; break;
    }

    // set childs for update and reset flag
    set_update(LEFT(v), t[v].upd);
    set_update(RIGHT(v), t[v].upd);
    t[v].upd = ' ';
}

void update(int v, int l, int r, char type) {
    if(l <= t[v].b && t[v].e <= r) // fits in the interval
        set_update(v, type);
    do_update(v);
    if(l > t[v].e || r < t[v].b) return;
    if(!(l <= t[v].b && t[v].e <= r)) {
        update(LEFT(v), l, r, type);
        update(RIGHT(v), l, r, type);
        t[v].val = t[LEFT(v)].val + t[RIGHT(v)].val;
    }
}

int query(int v, int l, int r) {
    int a = 0;
    do_update(v);

    if(l > t[v].e || r < t[v].b) a = 0;
    else if(l <= t[v].b && t[v].e <= r) a = t[v].val;
    else {
        a = query(LEFT(v), l, r) + query(RIGHT(v), l, r);
        t[v].val = t[LEFT(v)].val + t[RIGHT(v)].val;
    }

    return a;
}

int main() {
    int t;
    scanf("%d", &t);

    for(int case_id = 1; case_id <= t; case_id++) {
        int m, q, pirates = 1;
        scanf("%d", &m);
        while(m--) {
            int reps;
            scanf("%d%s", &reps, s);
            for(int i = 0; i < reps; i++) {
                for(int j = 0; s[j]; j++)
                    a[pirates++] = s[j] - '0';
            }
        }

        // init tree
        init(1, 1, pirates);
        printf("Case %d:\n", case_id);

        scanf("%d", &q);
        for(int i = 1; q--;) {
            char cmd[3];
            int l, r;
            scanf("%s%d%d", cmd, &l, &r);
            l++, r++;
            if(cmd[0] == 'S') printf("Q%d: %d\n", i++, query(1, l, r)); // query
            else update(1, l, r, cmd[0]); // update
        }
    }

    return 0;
}

