#include <algorithm>
#include <complex>
#include <list>
#include <stack>
#include <bitset>
#include <locale>
#include <stdexcept>
#include <cassert>
#include <map>
#include <cctype>
#include <string>
#include <cfloat>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <utility>
#include <climits>
#include <cstring>
#include <istream>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <deque>
#include <limits>
#include <sstream>

#define D(x) cerr << #x " = " << (x) << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int MAXN = 60 + 10;
string line;
int cnt['Z' - 'A' + 10];

int main() {
	ios_base::sync_with_stdio(false);
	while(getline(cin, line)) {
		if(line == "END") break;
		int n = line.length();
		memset(cnt, 0, sizeof(cnt));
		REP(i, 0, n) {			
			if(line[i] == ' ') continue;
			cnt[line[i] - 'A']++;			
		}
		bool ok = true;
		REP(i, 0, 26) {
			if(cnt[i] > 1) {
				ok = false;
				break;
			}
		} 
		if(ok) puts(line.c_str());
	}
}
