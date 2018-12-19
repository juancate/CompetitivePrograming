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

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> ans(k, 1);
    ans.push_back(n);
    REP(i, 0, k-1) ans.push_back(n+1);
    int last = ans[ans.size() - 1] + n - 1;
    if(m >= n) {
        int div = m / n;
        REP(i, 0, div) {
            ans.push_back(last);
            REP(i, 0, k-1)
                ans.push_back(last + 1);
            last = last + n;
        }
    }
    cout << ans.size() << endl;
    REP(i, 0, ans.size())
        cout << ans[i] << ' ';
    cout << endl;
}

