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

string info[101];
string drinks[] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN",
                   "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};

int main() {
  ios_base::sync_with_stdio(false);

  set<string> drink_set;
  for(int i = 0; i < 11; i++)
    drink_set.insert(drinks[i]);

  int n;
  cin >> n;

  int ans = 0;
  for(int i = 0; i < n; i++) {
    cin >> info[i];
    if(isdigit(info[i][0])) {
      int age = atoi(info[i].c_str());
      if(age < 18)
        ans++;
    }
    else {
      if(drink_set.count(info[i]))
        ans++;
    }
  }

  cout << ans << endl;

  return 0;
}

