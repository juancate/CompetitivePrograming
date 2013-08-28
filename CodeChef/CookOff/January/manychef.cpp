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

int n;
char s[2015];

void solve() {
    for(int i = n-1; i >= 0; i--) {
        if((s[i] == 'F' || s[i] == '?') && i >= 3) {
            if(s[i-1] == 'E' || s[i-1] == '?') {
                if(s[i-2] == 'H' || s[i-2] == '?') {
                    if(s[i-3] == 'C' || s[i-3] == '?') {
                        s[i-3] = 'C', s[i-2] = 'H', s[i-1] = 'E', s[i] = 'F';
                        i -= 3;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
        if(s[i] == '?') s[i] = 'A';
    puts(s);
}

int main() {
    int t;
    sscanf(gets(s), "%d", &t);

    while(t--) {
        gets(s);
        n = (int)strlen(s);

        solve();
    }

    return 0;
}

