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

// Problem: 11855 - Buzzwords
// Algorithm: Suffix Array + matching

const int maxn = 1010;

string T;
int n;
int SA[maxn];

bool cmp(int i, int j) {
    return T.substr(i) < T.substr(j);
}

void constructSA() {
    int i;
    for(i = 0; i < n; i++)
        SA[i] = i;

    sort(SA, SA + n, cmp);
}

// END Suffix Array

int m, len[maxn];
string line;

int len_match(int i, int j) {
    string a(T.substr(SA[i])), b(T.substr(SA[j]));
    int to = min(a.size(), b.size());

    for(int k = 0; k < to; k++) {
        if(a[k] != b[k])
            return k;
    }
    return to;
}

int main() {
    ios_base::sync_with_stdio(false);

    while(getline(cin, line) && line.size()) {

        stringstream ss(line);
        string s;
        T.clear();

        while(ss >> s) {
            T += s;
        }
        n = T.size();

        constructSA();

        memset(len, 0, sizeof(len));

        for(int i = 0; i < n-1; i++) {
            len[i] = len_match(i, i+1);
        }

        for(m = 1; ; m++) {
            int best = 0;
            int cnt = 0;

            for(int i = 0; i < n; i++) {
                if(len[i] >= m)
                    cnt++;
                else {
                    best = max(best, cnt);
                    cnt = 0;
                }
            }
            if(best == 0) break;
            cout << (best+1) << endl;
        }

        cout << endl;
    }
}

