#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

// Algorithm: Binary Search

int n, m, t;
int h[111111];

//bool check(double dist) {
bool check(int dist) {
  int checkpoints = 1;
  int point = h[0] + dist;
  for(int i = 1; i < m; i++) {
    int diff = fabs(h[i] - point);
    if(diff > dist) {
      point = h[i] + dist; 
      checkpoints++;
    }
  }
  return (checkpoints <= n);
}

double binarySearch() {
  //double lo = 0.0, hi = h[m-1];
  int lo = 0, hi = h[m-1];

  //while(fabs(hi - lo) > 1e-9) {
  while(lo < hi) {
    //double mid = lo + ((hi-lo) / 2.0);
    int mid = lo + (hi - lo) / 2;
    //D(mid);
    if(check(mid)) hi = mid;
    else lo = mid+1;
  }
  //return lo;

  return lo/10.;
}

int main() {
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d", &n, &m);

    REP(i, m) scanf("%d", &h[i]), h[i] *= 10;
    sort(h, h+m);
    
    printf("%.1lf\n", binarySearch());
  }
}
