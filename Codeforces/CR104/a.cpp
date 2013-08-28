#include <cstdio>
#include <cstdlib>
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

using namespace std;

int main() {
	int n;
	cin >> n;
	string num;
	cin >> num;
	int sum1 = 0, sum2 = 0;
	for(int i = 0; i < n; i++) {
		int val = num[i] - '0';
		if(val != 4 && val != 7) {
			puts("NO");
			return 0;
		}
		if(i < n/2) sum1 += val;
		else sum2 += val;
	}
	puts((sum1 == sum2)? "YES" : "NO");
}
