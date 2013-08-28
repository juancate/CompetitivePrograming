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

const double PI = acos(-1.0);
const double EPS = 1e-19;

int main() {
	int n, cases = 1;
	while(~scanf("%d", &n) and n != 0) {
		int max = 0;
		double maxCost = (1LL<<32);
		REP(i, 0, n) {
			int d, c;
			scanf("%d %d", &d, &c);
			double r = d / 2.;
			double ans = (c / (PI * r * r)) * 100.;
			//D(ans);
			if(ans < maxCost) {
				max = d;
				maxCost = ans;
			}
		}
		printf("Menu %d: %d\n", cases++, max);
	}
}
