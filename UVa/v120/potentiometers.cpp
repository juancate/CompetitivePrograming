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

#define LSOne(S) (S & (-S))

typedef vector<int> vi;

void ft_create(vi& t, int n) {
    t.assign(n+1, 0);
}

int ft_rsq(const vi& t, int b) {
    int sum = 0;
    for(; b; b -= LSOne(b)) sum += t[b];
    return sum;
}

int ft_rsq(const vi& t, int a, int b) {
    return ft_rsq(t, b) - (a == 1? 0 : ft_rsq(t, a-1));
}

void ft_adjust(vi& t, int k, int v) {
    for(; k <= (int)t.size(); k += LSOne(k)) t[k] += v;
}

char buffer[10010];

int main() {
    int n, case_id = 1;
    while(sscanf(gets(buffer), "%d", &n)) {
        if(n == 0) break;

        vi ft;
        ft_create(ft, n);

        for(int i = 1; i <= n; i++) {
            int x;
            sscanf(gets(buffer), "%d", &x);
            ft_adjust(ft, i, x - ft_rsq(ft, i, i));
        }

        if(case_id > 1) puts("");
        printf("Case %d:\n", case_id++);

        while(gets(buffer)) {
            if(buffer[0] == 'E') break;
            char op;
            int i, j;
            sscanf(buffer, "%c%d%d", &op, &i, &j);
            if(op == 'S')
                ft_adjust(ft, i, j - ft_rsq(ft, i, i));
            else {
                printf("%d\n", ft_rsq(ft, i, j));
            }
        }
    }
}

