#include <cstdlib>
#include <cmath>
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

using namespace std;

int main() {
	string sa, sb;
	cin >> sa >> sb;
	int ans = 0, n = sa.length();
	int fours = 0, sevens = 0;

	for(int i = 0; i < n; i++) {
		if(sa[i] != sb[i]) {
			if(sa[i] == '7') sevens++;
			else fours++;
		}
	}
	
	ans = max(fours, sevens);
	cout << ans << endl;
}

