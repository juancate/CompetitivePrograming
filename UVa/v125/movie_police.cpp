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
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int maxs = 100;
const int maxn = 1010;

int len[maxn];
string movies[maxn];

int main() {
  ios_base::sync_with_stdio(false);

  int n, m;
  while((cin >> n >> m) && (n|m)) {
    REP(i, 0, n) {
      string s; cin >> s;
      movies[i] = s;
      len[i] = s.size();
    }

    REP(i, 0, m) {
      string s; cin >> s;
      int ans = INF, index = 0;
      REP(j, 0, n) {
        int curr = INF;

        REP(k, 0, len[j] - s.length() + 1) {
          int cnt = 0;
          REP(l, 0, s.length()) {
            if(s[l] != movies[j][k+l])
              cnt++;
          }
          curr = min(curr, cnt);
        }

        if(curr < ans) {
          ans = curr;
          index = j;
        }
      }
      cout << (index+1) << endl;
    }
  }
}

