#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define INF 10000000

// Knapsack

using namespace std;

typedef pair<int, int> ii;

//int dp[501][100];
int memo[501][100][2];
int cost[100], fun[100];
int W, N;

ii rec(int w, int i) {
	if(i >= N) return ii(0, 0);

	if(memo[w][i][0] != -1) return ii(memo[w][i][0], memo[w][i][1]);

	ii a = rec(w, i+1);
	ii b = ii(-INF,0);
	if(cost[i] <= w) {
		b = rec(w - cost[i], i+1);
		b.first += fun[i];
		b.second -= cost[i];
	}

	ii ans = max(a, b);
	
	memo[w][i][0] = ans.first, memo[w][i][1] = ans.second;
	return ii(memo[w][i][0], memo[w][i][1]);
}

int main() {
	while(true) {
		scanf("%d %d\n", &W, &N);
		if((W|N) == 0) break;

		for(int i = 0; i < N; i++) 
			scanf("%d %d\n", &cost[i], &fun[i]);
		scanf("\n");

		memset(memo, -1, sizeof(memo));
		ii ans = rec(W, 0);
		printf("%d %d\n", -ans.second, ans.first);
	}
}
