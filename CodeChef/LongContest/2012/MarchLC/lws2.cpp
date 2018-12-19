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

const int MAXN = 2000 + 10;

int lws(string & s, int mode, int order) {
  int n = s.length(), imax = 0;
  int cnt[n], seq[n];
  if(n == 0) return 0;
  REP(i, n) cnt[i] = 1, seq[i] = i;
  //D(s);
  REP(i,n) REP(j,i) {
    if((mode == 0)? (s[i] >= s[j]) : (s[i] <= s[j]) and cnt[i] < cnt[j]+1) {
      cnt[i] = cnt[j]+1, seq[i] = j;
    }
  }
  REP(i,n) if(cnt[imax] <= cnt[i]) imax = i;
  //D(imax); D(cnt[imax]);
  if(order == 1) return cnt[imax];

  int j = imax;
  string str, cpy = "";
  while(seq[j] != j) str += s[j], j = seq[j];
  str += s[j];

  reverse(ALL(str));
  //D(str);  
  int last = -1;
  REP(i, str.length()) {
    for(int j = last+1; j < n; j++) {
      if(str[i] == s[j]) { last = j; break; }
      else cpy += s[j];
    }
  }
  s = cpy;
  //D(cpy);
  return cnt[imax];
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    char line[MAXN];
    scanf("%s", line);
    string word = line;
    string cpy = word;
    int first = lws(word, 0, 0) + lws(word, 1, 1);
    //cerr << "-----------\n";
    int second = lws(cpy, 1, 0) + lws(cpy, 0, 1);
    int ans = max(first, second);
    printf("%d\n", ans);
  }
}

