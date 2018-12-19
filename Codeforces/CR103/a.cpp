#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

int main() {
	int n, min = 1000, max = -1, minpos = 0, maxpos = 0;
	cin >> n;
	vector<int> numbers(n);

	REP(i, n) {
		cin >> numbers[i];
	}
	for(int i = 0, j = n-1; i < n && j >= 0; i++, j--) {
		if(numbers[j] < min) min = numbers[j], minpos = j;
		if(numbers[i] > max) max = numbers[i], maxpos = i;
	}
	int ans = 0;
	ans = maxpos + (n - (minpos + 1));
	if(maxpos > minpos) ans--;
	cout << ans << endl;
}
