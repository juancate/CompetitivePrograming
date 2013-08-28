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

int main() {
  int T;
  scanf("%d\n", &T);
  char s[100000+10];
  while(T--) {
    int cnt = 0, i = 0;
    gets(s);
    while(s[i]) {
      if(isdigit(s[i]) && s[i] != '4' && s[i] != '7') cnt++;
      i++;
    }
    printf("%d\n", cnt);
  }
}

