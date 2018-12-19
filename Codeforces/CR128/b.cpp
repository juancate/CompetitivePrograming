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

const int MAXN = 1000 + 10;

int n, m;
bool paper[MAXN][MAXN];

bool can(int r, int c) {
    bool valid = true;
    int cnt = 0;

    if(r < 0 || c < 0) return false;

    for(int i = r; i < r + 3 && i < n && valid; i++) {
        for(int j = c; j < c + 3 && j < n && valid; j++) {
            if(!paper[i][j]) valid = false;
            else cnt++;
        }
    }

    if(valid && cnt == 9) return true;
    return false;
}

bool check(int r, int c) {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(can(r - i, c - j))
                return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(paper, false, sizeof(paper));

    cin >> n >> m;

    int ans = -1;
    bool valid = false;
    REP(i, 0, m) {
        int r, c;
        cin >> r >> c;
        r--, c--;
        paper[r][c] = true;

        if(check(r, c)) {
            valid = true;
            ans = i+1;
            break;
        }
    }

    if(valid) cout << ans << endl;
    else cout << -1 << endl;
}

