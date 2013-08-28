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
#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int maxn = 100010;

pair<int,int> songs[maxn];
map<int, int> best;

// si tienen la misma duración de última van las que ya han sido escuchadas

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    int n;
    scanf("%d", &n);

    best.clear();

    for(int i = 0; i < n; i++) {
      int b, d;
      scanf("%d%d", &b, &d);
      songs[i] = make_pair(b, d);
      if(!best.count(b))
        best[b] = i;
      else if(songs[best[b]].second > songs[i].second)
        best[b] = i;
    }

    int bands = 0;
    long long ans = 0;

    vector<int> durations;
    foreach(it, best) {
      int d = songs[it->second].second;
      durations.push_back(d);
    }

    sort(durations.begin(), durations.end());

    for(int i = 0; i < durations.size(); i++) {
      bands++;
      ans += (long long)bands * (long long)durations[i];
    }

    for(int i = 0; i < n; i++) {
      if(best[songs[i].first] != i) {
        ans += (long long)bands * (long long)songs[i].second;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}

