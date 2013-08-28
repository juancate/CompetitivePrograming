#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
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

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

#define INF 1<<30
#define EPS 1e-13

using namespace std;

#define MAXN ((4+1) + 1000*(2*(2+1) + (3+1)) + 10)

char buff[MAXN];
int move;

int main() {
	int T;
	char* end = buff;
	fread(buff, 1, MAXN, stdin);
	T = strtol(end, &end, 10);
	//move = sscanf(end, "%d", &T);
	//end = end + move + 1;
	REP(i,T) {
		int N, K, P;
		N = strtol(end, &end, 10); K = strtol(end, &end, 10); P = strtol(end, &end, 10);
		//move = sscanf(end, "%d %d %d", &N, &K, &P);
		//end = end + move + 3;
		int ans = (K+P);
		printf("Case %d: %d\n", (i+1), (ans % N == 0)? N : (ans > N)? ans%N : ans);
	}
}

