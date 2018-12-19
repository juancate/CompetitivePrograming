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

string s[18300][1000];
int m[18300][1000], rows, cols;

int tonum(const string& r) {
    int nr = 0;
    for(int i = r.size(), j = 1; i--; j *= 26) {
        nr = (j * ((r[i] - 'A') + 1)) + nr;
    }
    return nr;
}

vector< pair<int, int> > split(const string& x) {
    vector< pair<int, int> > vs;
    for(int i = 1; i < x.size(); i++) {
        vs.push_back(make_pair(-1,-1));
        string y;
        while(i < x.size() && x[i] != '+') {
            y.push_back(x[i++]);
            if(isdigit(x[i]) && isalpha(x[i-1])) {
                vs.back().first = tonum(y);
                y = "";
            }
        }
        vs.back().second = atoi(y.c_str());
    }
    return vs;
}

int eval(int r, int c) {
    if(m[r][c] != -1) return m[r][c];

    int sum = 0;
    vector< pair<int, int> > form = split(s[r][c]);
    for(int i = 0; i < form.size(); i++) {
        int nc = form[i].first;
        int nr = form[i].second;
        sum += eval(nr, nc);
    }

    return m[r][c] = sum;
}

void solve() {
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= cols; j++) {
            if(m[i][j] == -1) {
                m[i][j] = eval(i, j);
            }
            if(j > 1) cout << ' ';
            cout << m[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--) {
        cin >> cols >> rows;

        for(int i = 1; i <= rows; i++) {
            string _s;
            for(int j = 1; j <= cols; j++) {
                m[i][j] = -1;
                cin >> _s;
                if(_s[0] == '=') s[i][j] = _s;
                else m[i][j] = atoi(_s.c_str());
            }
        }

        solve();
    }

    return 0;
}

