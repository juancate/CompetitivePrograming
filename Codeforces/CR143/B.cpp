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

int n, d, l;
vector<int> ans, prev;
bool ok;

void solve(int k, int currentD) {
    if(k == n-1) {
        if(currentD > 0 && currentD <= l) {
            ok = true;
            ans[k] = currentD;
        }
        return;
    }

    if(k > 0) {
        cerr << "k = " << k << " ans[k-1] = " << ans[k-1] << " prev[k-1] = " << prev[k-1]
             << " currentD = " << currentD << endl;
        for(int i = 1; i <= l; i++) {
            int new_card = i - currentD;
            if() {
                cerr << " i = " << i << endl;
                ans[k] = i;
                prev[k] = new_card;
                solve(k+1, new_card);
            }
            if(ok) return;
        }
    }
    else if(k == 0) {
        for(int i = 1; i <= l; i++) {
            ans[k] = i;
            solve(k+1, i - currentD);
            if(ok) return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> d >> l;
    ans.resize(n);
    prev.resize(n);
    prev[0] = d;
    ok = false;
    solve(0, d);

    if(ok) {
        REP(i, 0, n) cout << ans[i] << ' ';
        cout << endl;
    }
    else {
        cout << "-1" << endl;;
    }
}

