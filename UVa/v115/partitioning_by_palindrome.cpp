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

// Problem: 11584 - Partitioning by Palindromes
// Algorithm: DP, palindromes.

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

char word[1111];
int dp[1111];


bool palindrome(int start, int end) {
    while(start < end) {
        if(word[start] != word[end])
            return false;
        start++; end--;
    }
    return true;
}

int main() {
    int t; scanf("%d", &t);

    while(t--) {
        scanf("%s", word);

        memset(dp, 0x3f, sizeof(dp));
        int n = strlen(word);

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                if(palindrome(j, i)) {
                    dp[i+1] = min(dp[i+1], dp[j]+1);
                }
            }
        }
        printf("%d\n", dp[n]);
    }
}

