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

int main() {
    int x;
    int case_id = 0;
    while(scanf("%d", &x) && ~x) {
        vector<int> A;
        A.push_back(-x);
        while(scanf("%d", &x) && ~x)
            A.push_back(-x);

        vector<int> dp(A.size(), 1);

        dp[0] = 1;

        int n = (int)A.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(A[j] <= A[i])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }

        if(case_id) printf("\n");

        printf("Test #%d:\n", ++case_id);
        printf("  maximum possible interceptions: %d\n", *max_element(ALL(dp)));
    }
}

