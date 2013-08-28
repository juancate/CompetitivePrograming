#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;

  map<string, int> score;
  string leader;
  int best = -INF;

  for(int i = 0; i < n; i++) {
    string handle;
    int plus, minus;
    cin >> handle >> plus >> minus;
    score[handle] = plus*100 - minus*50;
    for(int j = 0; j < 5; j++) {
      int p;
      cin >> p;
      score[handle] += p;
    }
    if(best == -INF || score[handle] > best) {
      best = score[handle];
      leader = handle;
    }
  }

  cout << leader << endl;

  return 0;
}

