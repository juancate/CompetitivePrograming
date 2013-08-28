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
    int x, n;
    cin >> x;
    n = 3;

    if(x == 1) cout << 1 << endl;
    else if(x == 3) cout << 5 << endl;
    else {
        int inc = 0;
        for(int i = 2; i < 1000; i += inc) {
            if(x < i) {
                n -= 2;
                break;
            }
            n += 2;
            inc += 4;
        }
        cout << n << endl;
    }
}

