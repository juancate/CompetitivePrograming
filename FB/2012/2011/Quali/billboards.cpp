#include <cstdio>
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

vector<int> words;
int H, W, n;

bool overfilled(int s) {
	int sumH = 0;
	REP(i, n) {
		int sumW = words[i]*s;
		if(sumW > W) return true;
		while(i < n-1 && sumW + (words[i+1] + 1)*s <= W) {
			sumW += (words[++i] + 1)*s;
		}
		sumH += s;
	}
	if(sumH > H) return true;
	return false;
}

int binSearch() {
	int lo = 1, hi = W*2;
	
	while(lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if(overfilled(mid)) 
			hi = mid;
		else 
			lo = mid+1;
	}
	if(lo == 1 && overfilled(1)) return 0;
	return lo-1;
}

int main() {
	int T;
	cin >> T;
	cin.get();
	for(int id = 1; id <= T; id++) {
		string line, w;
		getline(cin, line);
		istringstream iss(line);
		iss >> W >> H;
		while(iss >> w) { words.push_back(w.length()); }
	
		n = words.size();
		int ans = binSearch();

		printf("Case #%d: %d\n", id, ans);
		words.clear();
	}
}
