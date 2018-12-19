#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, string> is;

int main() {
	int n;
	cin >> n;
	vector<is> q(n);
	int h[n] = {0};
	for(int i = 0; i < n; i++) {
		string name;
		int j;
		cin >> name >> j;
		q[i] = is(j, name);
	}
	sort(q.begin(), q.end());
	h[0] = 1;
	int i;
	for(i = 1; i < n && q[i].first == 0; i++) {
		h[i] = h[i-1]+1;
	}
	
}
