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

  int n, k;
  cin >> n >> k;

  vector<int> b(n);
  for(int i = 0; i < n; i++)
    cin >> b[i];

  vector<int> a;
  for(int i = 0; i < n; i++)
    if(b[i] == 0)
      a.push_back(i);

  for(int i = n-1; i >= 0; i--)
    if(b[i] > 0) {
      int cnt = 0;
      int index = -1;
      for(int j = 0; j < a.size(); j++) {
        if(a[j] >= i+k)
          cnt++;
        if(cnt == b[i]) {
          index = j+1;
          break;
        }
      }
      a.insert(a.begin()+index, i);
    }

  for(int i = 0; i < n; i++)
    cout << a[i]+1 << " ";
  cout << endl;

  return 0;
}

