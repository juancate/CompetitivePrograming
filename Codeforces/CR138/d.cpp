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
#define sz(v) (int)(v).size()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

const int maxn = 2 * 100010;

int n, m, b[maxn], total;
bool alpha[30];
set<int> cp;
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
    bool ok = false;

    while(i < n && !ok) {

        while(j >= 0 && T[i] != P[j]) j = b[j];

        i++; j++;

        if(j == m) {
            int cnt = 0;
            FOREACH(ch, cp) {
                if(alpha[*ch - 'a'])
                    cnt++;
            }
            if(cnt == total) {
                ok = true;
            } else {
                ok = false;
            }
        }
    }

    if(ok) cout << "Yes\n";
    else cout << "No\n";
}


int main() {
    ios_base::sync_with_stdio(false);

    memset(alpha, false, sizeof(alpha));

    cin >> T >> P;

    n = sz(T);
    m = sz(P);

    REP(i, 0, n)
        alpha[T[i] - 'a'] = true;

    total = count(alpha, alpha + 30, true);

    REP(i, 0, m)
        cp.insert(P[i]);

    kmp_preprocess();
    kmp();
}

