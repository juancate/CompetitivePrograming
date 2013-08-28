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

bool common(int a, int b) {
    vector<int> cnt_a(10, 0), cnt_b(10, 0);

    while(a > 0) {
        cnt_a[a % 10]++;
        a /= 10;
    }

    while(b > 0) {
        cnt_b[b % 10]++;
        b /= 10;
    }

    for(int i = 0; i < 10; i++) {
        if(cnt_a[i] == 0 || cnt_b[i] == 0)
            continue;

        if(cnt_a[i] != 0 && cnt_b[i] != 0)
            return true;
    }

    return false;
}

int solve(int n) {
    vector<bool> fact(sqrt(n) + 10, false);
    D(fact.size());

    int cnt = 1;

    for(int i = 2; i * i <= n; i++) {
        if(!fact[i]) {
            if(n % i == 0) {
                if(common(i, n))
                    cnt++;
            }
            fact[i] = true;
        }
        if(!fact[n / i]) {
            if(n % (n / i) == 0) {
                if(common(n / i, n))
                    cnt++;
            }
            fact[n / i] = true;
        }
    }

    if(n != 1 && common(1, n))
        cnt++;

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    cout << solve(n) << endl;
}

