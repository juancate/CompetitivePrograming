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

char message[25][500];
char s[500];

int main() {
  while(true) {
    int n, m;
    scanf("%d", &m);
    if(m == 0) break;
    scanf("%s", s);
    bool reverse = false;
    int len = strlen(s);
    int row = 0;
    memset(message, 0, sizeof(message));

    REP(i, len) {
      int col = (reverse)? m-1 : 0;
      int limit = (reverse)? -1 : m;
      while(col != limit) {
        message[row][col] = s[i];
        if(reverse) col--;
        else col++;
        i++;
      }
      i--;
      reverse = !reverse;
      row++;
    }
    n = len/m;

    REP(i, m) REP(j, n) printf("%c", message[j][i]);
    puts("");
  }
}

