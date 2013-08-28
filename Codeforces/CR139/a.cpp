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

    int n, x;
    cin >> n >> x;

    int next = 7 - x;
    int current = x;
    bool ok = true;

    for(int i = 0; i < n && ok; i++) {
        int a, b; cin >> a >> b;
        vector<bool> f(7, false);
        f[a] = f[b] = f[7-a] = f[7-b] = true;
        if(f[next]) {
            ok = false;
        }
        current = next;
        next = 7 - current;
    }

    cout << (ok? "YES" : "NO") << endl;
}

