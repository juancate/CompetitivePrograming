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

int main() {
    int n, b;
    while(scanf("%d%d", &n, &b)) {
        if((n|b) == 0) break;

        vector<bool> used(n+1, false);
        vector<int> bag(b);

        for(int i = 0; i < b; i++) {
            scanf("%d", &bag[i]);
            for(int j = 0; j <= i; j++) {
                used[abs(bag[i] - bag[j])] = true;
            }
        }
        int cnt = count(ALL(used), false);
        puts((cnt)? "N" : "Y");
    }
    return 0;
}

