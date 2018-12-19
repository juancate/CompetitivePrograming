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
#include <climits>

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

map<long long, int> fibo;
int nums[111];
char text[111], s[111];

int main() {
  int t;
  scanf("%d", &t);

  fibo[1] = 0, fibo[2] = 1;
  long long a = 1, b = 2, c;
  for(int i = 2; i < 45; i++) {
    c = a + b;
    fibo[c] = i;
    a = b, b = c;
  }

  while(t--) {
    int n;
    scanf("%d", &n);
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++) {
      scanf("%d", &nums[i]);
      if(maxi < nums[i])
        maxi = nums[i];
    }
    while(getchar() != '\n');
    fgets(s, sizeof s, stdin);

    memset(text, ' ', sizeof text);
    text[fibo[maxi]+1] = 0;
    for(int i = 0, j = 0; s[i+1] && j < n; i++) {
      if(isupper(s[i])) {
        text[fibo[nums[j]]] = s[i];
        j++;
      }
    }

    printf("%s\n", text);
  }

  return 0;
}

