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
  int T;
  cin >> T;
  cin.get();
  string goal = "HACKERUP";
  for(int id = 1; id <= T; id++) {
    map<char, int> times;
    FOREACH(it, goal) {
      char ch = *it;
      times[ch] = 0;
    }
    string line;
    getline(cin, line);
    FOREACH(it, line) {
      if(goal.find(*it) != string::npos)
				times[*it]++;
    }
		times['C'] = times['C']/2;
    int best = 1000000;
    FOREACH(it, times)
      best = min(best, it->second);
    printf("Case #%d: %d\n", id, best);
  }
}
