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
        int n; scanf("%d", &n);

        string ans = "";

        bool valid = true;

        while(n >= 10 && valid) {
            int prev = n;

            for(int i = 9; i >= 2; i--) {
                if(n % i == 0) {
                    ans.push_back(i + '0');
                    n /= i;
                    break;
                }
            }

            if(prev == n) valid = false;
        }

        sort(ALL(ans));
        if(!valid) puts("-1");
        else printf("%d%s\n", n, ans.c_str());
    }
}

