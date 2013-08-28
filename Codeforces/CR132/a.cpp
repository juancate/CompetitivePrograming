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
    int n, m;
    cin >> n;

    vector<int> A(n);

    REP(i, 0, n) cin >> A[i];

    cin >> m;
    vector<int> B(m);

    REP(i, 0, m) cin >> B[i];

    int cnt = 0, max_ratio = -INF;

    REP(i, 0, n) {
        REP(j, 0, m) {
            if(B[j] % A[i] == 0) {
                int ratio = B[j] / A[i];
                if(ratio > max_ratio) {
                    max_ratio = ratio;
                    cnt = 1;
                } else if(ratio == max_ratio) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
}

