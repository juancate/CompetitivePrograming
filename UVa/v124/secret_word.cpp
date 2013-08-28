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

// Problem: 12467 - Secret Word
// Algorithm: KMP

const int MAXN = 1e6 + 10;

int n, m, b[MAXN];
string T, P;

void kmp_preprocess() {
    int i = 0, j = -1;
    b[0] = -1;

    while(i < m) {
        while(j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

void kmp() {
    int i = 0, j = 0;

    int best = 0;

    while(i < n) {

        while(j >= 0 && T[i] != P[j]) j = b[j];
        //mod orig: if(j == m) // match, m is length of P
        if(T[i] == P[j]) {
            if(j+1 > best)
                best = j+1;
        }
        i++; j++;
    }
    string ans = P.substr(0, best);
    reverse(ALL(ans));
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while(t--) {
        cin >> T; P = T;
        reverse(ALL(T));

        n = m = T.size();
        kmp_preprocess();
        kmp();
    }
}

