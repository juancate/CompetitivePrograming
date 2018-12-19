#include <cmath>
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

typedef pair<int, int> ii;

int sqr(int x) {
	return x*x;
}

int main() {
	ii ini, fin;
	cin >> ini.first >> ini.second >> fin.first >> fin.second;
	int n;
	cin >> n;
	vector<pair<ii, int> > radiators(n);

	for(int i = 0; i < n; i++) {
		int x, y, r;
		cin >> x >> y >> r;
		radiators[i] = make_pair(ii(x, y), r);
	}

	vector<ii> points;

	for(int i = min(ini.first, fin.first); i <= max(ini.first, fin.first); i++) {
		points.push_back(ii(i, fin.second));
		points.push_back(ii(i, ini.second));
	}
	for(int i = min(ini.second, fin.second) + 1; i < max(ini.second, fin.second); i++) {
		points.push_back(ii(ini.first, i));
		points.push_back(ii(fin.first, i));
	}
	
	sort(points.begin(), points.end());
	sort(radiators.begin(), radiators.end());
	//FOREACH(it, points) cout << it->first << " " << it->second << endl;
	int ans = 0;
	map<ii, bool> visited;
	for(int i = 0; i < n; i++) {
		ii rad = radiators[i].first;
		int radio = radiators[i].second;
		for(int j = 0; j < points.size(); j++) {
			if(visited.find(points[j]) != visited.end()) continue;
			int dist = sqr(rad.first - points[j].first) + sqr(rad.second - points[j].second);
			if(dist <= sqr(radio)) {
				visited[points[j]] = true;
			}
		}
	}
	ans = points.size() - visited.size();
	cout << ans << endl;
}
