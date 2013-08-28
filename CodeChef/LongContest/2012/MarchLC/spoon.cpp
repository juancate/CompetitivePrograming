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

int R, C;
vector<string> matrix;
char line[200];

bool valid(int i, int pos) {
  if(pos + 4 < C and tolower(matrix[i][pos+1]) == 'p')
    if(tolower(matrix[i][pos+2]) == 'o' and tolower(matrix[i][pos+3]) == 'o')
      if(tolower(matrix[i][pos+4]) == 'n') return true;
                    
  if(i + 4 < R and tolower(matrix[i+1][pos]) == 'p')
    if(tolower(matrix[i+2][pos]) == 'o' and tolower(matrix[i+3][pos]) == 'o')
      if(tolower(matrix[i+4][pos]) == 'n') return true;  

  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d", &R, &C);
    matrix.resize(R);
    REP(i, R) {
      scanf("%s", line);
      matrix[i] = line;
    }

    bool spoon = false;

    REP(i, R) {      
      REP(j, C) {
        if(tolower(matrix[i][j]) == 's' and valid(i, j)) {
          spoon = true;
          break;
        }
      }
    }

    if(spoon) puts("There is a spoon!");
    else puts("There is indeed no spoon!");
  }
}

