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
		//D(i);
		int sumW = words[i]*s;
		if(sumW > W) return true;
		while(i < n-1 && sumW + (words[i+1] + 1)*s <= W) {
			sumW += (words[++i] + 1)*s;
		}
		sumH += s;
		//D(sumW); D(s); D(sumH);
	}
	if(sumH > H) return true;
	//cerr << "false" << endl;
	return false;
}

int fullSearch() {
	int size;
	for(size = min(H, W); size > 0; size--) {
		//cerr << "-------------" << endl;
		if(!overfilled(size)) break;
	}
	if(size == 1 && overfilled(size)) return 0;
	return size;
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
		int ans = fullSearch();
		//int ans = binSearch();

		printf("Case #%d: %d\n", id, ans);
		words.clear();
	}
}
