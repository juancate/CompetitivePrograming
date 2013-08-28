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

// Problem: 11569 - Lovely Hint
// Algorithm: DP

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

string str;
char word[300];
int dp[30][30];

int main() {
    int t; scanf("%d\n", &t);

    while(t--) {
        gets(word);

        str.clear();

        for(int i = 0; word[i]; i++) {
            if(isupper(word[i]))
                str += word[i];
        }

        sort(ALL(str));
        str.resize(unique(ALL(str)) - str.begin());

        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < str.size(); i++) {
            int k = str[i] - 'A';
            dp[1][k] = 1;
        }

        for(int i = 2; i <= str.size(); i++) {
            for(int j = 1; j <= str.size(); j++) {
                for(int k = 1; k <= str.size(); k++) {
                    if(k == j) continue;
                    int p = (str[j-1] - 'A' + 1) * 5;
                    int q = (str[k-1] - 'A' + 1) * 4;

                    if(p <= k) {
                        dp[i][j] += dp[i-1][k];
                    }
                }
            }
        }

        int ans = -1;

        for(int i = 26; i >= 0; i--) {
            for(int j = 0; j <= 26; j++) {
                if(dp[i][j] != 0) {
                    ans = i;
                    break;
                }
            }
            if(ans >= 0) break;
        }

        int sum = 0;

        REP(i, 0, 27) if(dp[ans][i]) sum++;
        printf("%d %d\n", ans, sum);
    }
}

