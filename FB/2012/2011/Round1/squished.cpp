#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
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

#define MOD 0xfaceb00c

using namespace std;

typedef long long ll;
#define long ll

int M;
int memo[255+1];

long rec(int n) {
	if(n == 0) return 0;
	D(n);
	if(n <= M && memo[n] != -1) return memo[n];
	int div = n/10;
	if(div == 0) return 0;
	int mod = n%10;
	long ans = 0;
	if(div <= M && mod <= M && mod > 0) ans++; // valid partition
	if(n <= M) ans++;
	ans = ans + rec(div) + rec(mod);
	memo[n] = (ans%MOD);
	return (ans%MOD);
}

int main() {
	int T;
	cin >> T;
	for(int id = 1; id <= T; id++) {
		int n;
		cin >> M >> n;
		memset(memo, -1, sizeof(memo));
		int ans = (int)rec(n);
		printf("Case #%d: %d\n", id, ans);
	}
}
