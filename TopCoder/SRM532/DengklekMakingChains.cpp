#line 107 "DengklekMakingChains.cpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

class DengklekMakingChains {
public:
  int maxBeauty(vector <string> chains) {
    int sum = 0, bestmid = -1;

    chains.push_back("...");
    vector<int> ml(chains.size(), 0), mr(chains.size(), 0);

    for(int i = 0; i < chains.size(); i++) {
      if(chains[i].find(".") == string::npos) {
        sum += (chains[i][0] - '0') + (chains[i][1] - '0')  + (chains[i][2] - '0');
      }
      else if(chains[i][0] == '.' and chains[i][1] != '.' and chains[i][2] == '.') {
        bestmid = max(bestmid, (chains[i][1] - '0'));
      }
      else {
        for(int j = 0; j < 3; j++) {
          if(chains[i][j] == '.') break;
          ml[i] += chains[i][j] - '0';
        }
        for(int j = 2; j >= 0; j--) {
          if(chains[i][j] == '.') break;
          mr[i] += chains[i][j] - '0';
        }
      }
    }

    int bestpair = 0;

    REP(i, chains.size()) {
      if(chains[i].find(".") == string::npos) continue;
      int r = 0;
      REP(j, chains.size()) {
        if(i != j and chains[j].find(".") != string::npos) {
          r = max(r, mr[j]);
        }
      }
      bestpair = max(bestpair, ml[i]+r);
    }
    
    sum += bestpair;
    return max(bestmid, sum);
	}
};

