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
vector<bool> isCoprime;
vector<int> numbers;

int main() {
    ios_base::sync_with_stdio(false);

    while(cin >> n) {
        isCoprime.assign(n, true);
        numbers.assign(n, 0);

        for(int i = 0; i < n; i++) {
            cin >> numbers[i];
            for(int j = 0; j < i; j++) {
                if(__gcd(numbers[i], numbers[j]) != 1) {
                    isCoprime[i] = isCoprime[j] = false;
                }
            }
        }

        int x = -INF;
        for(int i = 0; i < n; i++)
            if(isCoprime[i])
                x = max(x, numbers[i]);
        cout << x << endl;
    }
}

