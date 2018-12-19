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
#include <set>
#include <map>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

const int MAXN = 1e5 + 10;

struct node {
    int x, cnt;
    node(int val = 0, int c = 0) {
        x = val, cnt = c;
    }
} tree[4*MAXN];

int a[MAXN], x;

void build(int v, int begin, int end) {
    if(begin == end) {
        tree[v] = node(a[begin], a[begin] == x);
    } else {
        int mid = (begin + end) / 2;

        build(2 * v, begin , mid);
        build(2 * v + 1, mid+1, end);

        if(tree[2*v].cnt > tree[2*v+1].cnt)
            tree[v] = tree[2*v];
        else
            tree[v] = tree[2*v+1];
    }
}

int query(int v, int t_begin, int t_end, int a_begin, int a_end) {
    if(t_begin >= a_begin && t_end <= a_end)
        return tree[v].cnt;

    int mid = (t_begin + t_end) / 2;
    int res = 0;

    if(mid >= a_begin && t_begin <= a_end)
        res += query(2*v, t_begin, mid, a_begin, a_end);
    if(t_end >= a_begin && mid+1 <= a_end)
        res += query(2*v + 1, mid+1, t_end, a_begin, a_end);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    REP(i, 0, n)
        cin >> a[i];

    build(1, 1, n);

    REP(i, 0, m) {
        int l, r; cin >> l >> r;

        cout << query(1, 1, n, l, r) << endl;
    }
}

