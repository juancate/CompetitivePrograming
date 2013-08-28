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
#define ALL(v) (v).begin(), (v).end()

#define INF 1<<30
#define EPS 1e-13

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  vector<string> text;
  string line;
  while(getline(cin, line)) text.push_back(line);

  int n = text.size();
  vector<bool> ampl(n, false);
  
  REP(i,n) {
    bool amplifier = false;
    REP(j, text[i].size()) {
      if(text[i][j] != ' ' and text[i][j] != '#') {
        break;
      }
      if(text[i][j] == '#') {
        amplifier = true;
        break;
      }
    }
    ampl[i] = amplifier;
  }
  
  REP(i,n) {
    if(ampl[i]) cout << text[i] << endl;
    else {
      for(int j = i; j < n and !ampl[j]; j++, i++) {
        for(int k = 0; k < text[j].size(); k++)
          if(text[j][k] != ' ') cout << text[j][k];
      }
      cout << endl;
      i--;
    }
  }
}

