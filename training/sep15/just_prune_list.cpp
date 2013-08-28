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


int main() {
    int t; scanf("%d", &t);

    while(t--) {
        int n, m;
        scanf("%d%d", &n, &m);

        vector<int> first, second;

        REP(i, 0, n) {
            int x; scanf("%d", &x);
            first.push_back(x);
        }

        REP(i, 0, m) {
            int x; scanf("%d", &x);
            second.push_back(x);
        }

        int changes = 0;
        vector<int> ans(min(first.size(), second.size()));

        sort(ALL(first));
        sort(ALL(second));

        vector<int>::iterator it = set_intersection(ALL(first), ALL(second), ans.begin());

        int sz = int(it - ans.begin());

        sz = (first.size() - sz) + (second.size() - sz);
        cout << sz << endl;
    }
}

