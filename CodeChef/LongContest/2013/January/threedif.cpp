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

using namespace std;

const int INF = (int)(1e9);

const int mod = INF + 7;
long long a[3];

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        for(int i = 0; i < 3; i++) {
            scanf("%lld", &a[i]);
        }
        sort(a, a+3);

        // (a[0] * a[1] * a[2]) - (a[0] * a[2] + 2 * (a[0] * a[1] - a[0]))
        long long ans = ((((a[0] % mod) * (a[1] % mod)) % mod) * (a[2] % mod)) % mod;
        long long diff = ((((a[0] % mod) * (a[2] % mod)) % mod) +
                          (2LL * ((((a[0] % mod) * (a[1] % mod)) % mod) - (a[0] % mod) + mod) % mod) % mod);

        diff %= mod;
        ans = (ans - diff + mod) % mod;

        printf("%d\n", int(ans));
    }
}

