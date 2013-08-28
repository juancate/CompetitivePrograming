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

// Problem: Headmaster's Headache
// Algorithm: DP + bitmask
// Status: Accepted

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int maxs = 9;
const int maxn = 110;

int n, s, m;
int dp[maxn][1<<maxs][1<<maxs], cost[maxn];
vector<int> subjects[maxn];

int solve(int teacher, int bitmask1, int bitmask2) {
    if(bitmask1 == (1 << s)-1 && bitmask2 == (1 << s) - 1)
        return 0;

    if(teacher == n) return INF;

    if(dp[teacher][bitmask1][bitmask2] != -1)
        return dp[teacher][bitmask1][bitmask2];

    int next_bitmask1 = bitmask1;
    int next_bitmask2 = bitmask2;

    for(int i = 0; i < (int)subjects[teacher].size(); i++) {
        int subject = subjects[teacher][i];

        if(!(next_bitmask1 & (1 << subject)))
            next_bitmask1 |= (1 << subject);
        else
            next_bitmask2 |= (1 << subject);
    }

    dp[teacher][bitmask1][bitmask2] = min(solve(teacher+1, bitmask1, bitmask2),
                                          cost[teacher] + solve(teacher+1, next_bitmask1, next_bitmask2));

    return dp[teacher][bitmask1][bitmask2];
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
#endif

    while(cin >> s >> m >> n) {
        if((s|m|n) == 0) break;

        int bitmask1 = 0, bitmask2 = 0;
        int ans = 0;
        string line;

        REP(i, 0, m) {
            int c; cin >> c;
            ans += c;

            getline(cin, line);
            stringstream ss(line);
            int subject;

            while(ss >> subject) {
                if(!(bitmask1 & (1 << (subject-1))))
                    bitmask1 |= (1 << (subject-1));
                else
                    bitmask2 |= (1 << (subject-1));
            }
        }

        REP(i, 0, n) {
            cin >> cost[i];
            subjects[i].clear();

            getline(cin, line);
            stringstream ss(line);
            int subject;

            while(ss >> subject) {
                subjects[i].push_back(subject-1);
            }
        }

        memset(dp, -1, sizeof(dp));

        ans += solve(0, bitmask1, bitmask2);
        cout << ans << endl;
    }
}

