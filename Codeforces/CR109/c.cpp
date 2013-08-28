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

#define INF 1<<30
#define EPS 1e-13

using namespace std;

vector<string> forbiddens;
int k;

int check(string str, int i) {
  REP(j,forbiddens.size()) {
    int l = i;
    int valid = true;
    D(forbiddens[j]);
    REP(m,forbiddens[j].size()) {
      if(l > str.size()) break;
      if(str[l] != forbiddens[j][m]) {
        valid = false;
        break;
      }
      l++;
    }
    if(valid) return forbiddens[j].size();
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  string sentence, cpy;
  cin >> sentence;
  cpy = sentence;
  int n = sentence.size(), ans = 0;
  cin >> k;
  REP(i,k) {
    string f;
    cin >> f;
    forbiddens.push_back(f);
  }
  int nk = forbiddens.size();

  REP(i,nk) REP(j,nk) {
    if(forbiddens[i][1] == forbiddens[j][0]) {
      ostringstream oss("");
      oss << forbiddens[i] << forbiddens[j][i];
      forbiddens.push_back(oss.str());
      oss.str("");
      oss << forbiddens[i][1] << forbiddens[i][0] << forbiddens[j][1];
      forbiddens.push_back(oss.str());
      oss.str("");
      oss << forbiddens[i][0] << forbiddens[j][1] << forbiddens[i][1];
      forbiddens.push_back(oss.str());
    }
  }

  REP(i,k) {
    string f = forbiddens[i];
    reverse(f.begin(), f.end());
    forbiddens.push_back(f);
  }
  
  
  for(int i = 0; i < n-1; i++) {
    int val = check(sentence, i);
    if(val != 0) {
      ans++;
      i += val-1;
    }
  }
  cout << ans << endl;
}

