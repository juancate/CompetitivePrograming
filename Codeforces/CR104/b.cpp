#include <cstdlib>
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

using namespace std;

string tostr(int c) {
	ostringstream oss;
	oss << c;
	return oss.str();
}

int mask(int c) {
	string sc = tostr(c);
	string ans;
	for(int i = 0; i < sc.length(); i++) {
		if(sc[i] == '4' || sc[i] == '7')
			ans += sc[i];
	}
	return atoi(ans.c_str());
}

int main() {
	string sa, sb;
	int a, b; 
	cin >> sa >> sb;
	a = atoi(sa.c_str());
	b = atoi(sb.c_str());
	if(a < b) cout << b << endl;
	else {
		int c;
		for(c = a+1; ; c++) {
			int maskc = mask(c);
			if(maskc == b) break;
		}
		cout << c << endl;
	}
}
