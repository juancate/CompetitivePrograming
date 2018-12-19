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

#define D(x) cerr << #x << " = " << x << endl;
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
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();

    if(m != n) {
        cout << "NO\n";
        return 0;
    }

    int cnt = 0, first = -1, second = -1;
    REP(i, 0, n) {
        if(a[i] != b[i]) {
            if(first == -1) first = i;
            else second = i;
            cnt++;
        }
    }
    if(cnt == 2) {
        swap(a[first], a[second]);
        if(a == b) cout << "YES\n";
        else cout << "NO\n";
    } else {
        cout << "NO\n";
    }
}

