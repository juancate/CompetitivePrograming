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

const int MAXN = 1000 + 10;
int days[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    REP(i, 0, n) cin >> days[i];

    if(n == 1) {
        cout << days[0] << endl;
        return 0;
    }

    int min = std::min(days[0], days[n-1]);
    pair<int, int> diff = make_pair(1, 2);
    int max = std::max(days[1], days[2]);

    REP(i, 1, n-2) {
        if ((days[i] < days[diff.first] || days[i] < days[diff.second])) {
            if(days[i+1] < days[diff.second] || days[i+1] < days[diff.first]) {
                diff = make_pair(i, i+1);
                max = std::max(days[i], days[i+1]);
            }
        }
    }
    min = std::min(min, max);
    cout << min << endl;
}

