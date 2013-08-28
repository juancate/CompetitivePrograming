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

long long fairs[44];

string to_str(long long x) {
  stringstream ss;
  ss << x;
  return ss.str();
}

bool is_pal(string x) {
  int i = 0, j = x.size()-1;

  while(i < j)
    if(x[i++] != x[j--])
      return false;
  return true;
}

const long long LIMIT = (long long)1e14;

int main() {
  int t, sz = 0;
  scanf("%d", &t);

  for(long long i = 1; i*i <= LIMIT; i++) {
    long long curr = i*i;
    if(is_pal(to_str(i)) && is_pal(to_str(curr))) {
      fairs[sz++] = curr;
    }
  }

  for(int case_id = 1; case_id <= t; case_id++) {
    long long A, B;
    scanf("%lld%lld", &A, &B);

    int l = 0, cnt = 0;
    while(fairs[l] < A) l++;
    for(int i = l; i < sz && fairs[i] <= B; i++) {
      cnt++;
    }

    printf("Case #%d: %d\n", case_id, cnt);
  }

  return 0;
}

