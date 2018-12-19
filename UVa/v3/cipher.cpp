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

const int maxn = 210;

int n, k, p[maxn], c[maxn];
string phrase;

int cycle_length(int pos) {
    int next = p[pos];
    int cnt = 1;

    while(next != pos) {
        cnt++;
        next = p[next];
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);

    while(cin >> n && n) {
        phrase = "";
        REP(i, 0, n) cin >> p[i], p[i]--;

        REP(i, 0, n)
            c[i] = cycle_length(i);

        cin.get();
        string ln;

        while(getline(cin, ln) && ln != "0") {
            int pos = ln.find(" ");

            k = atoi(ln.substr(0, pos).c_str());

            phrase = ln.substr(pos+1);
            while(phrase.size() < n) phrase.push_back(' ');

            string ans(n, ' ');

            REP(i, 0, n) {
                int cycle = k % c[i];
                int pos = p[i];

                REP(j, 0, cycle)
                    pos = p[pos];

                ans[pos] = phrase[p[i]];
            }
            cout << ans << endl;
        }
        cout << endl;
    }
}

