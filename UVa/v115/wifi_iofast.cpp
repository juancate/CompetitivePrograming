#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>
#include <climits>
#include <cassert>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

// Algorithm: Binary Search

/* Fast IO */
class FastInput {
public:
  FastInput() {
    m_dataOffset = 0;
    m_dataSize = 0;
    m_v = 0x80000000;
  }
  uint32_t ReadNext() {
    if (m_dataOffset == m_dataSize) {
      int r = read(0, m_buffer, sizeof(m_buffer));
      if (r <= 0) return m_v;
      m_dataOffset = 0;
      m_dataSize = 0;
      int i = 0;
      if (m_buffer[0] < '0') {
        if (m_v != 0x80000000) {
          m_data[m_dataSize++] = m_v;
          m_v = 0x80000000;
        }
        for (; (i < r) && (m_buffer[i] < '0'); ++i);
      }
      for (; i < r;) {
        if (m_buffer[i] >= '0') {
          m_v = m_v * 10 + m_buffer[i] - 48;
          ++i;
        } else {
          m_data[m_dataSize++] = m_v;
          m_v = 0x80000000;
          for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
        }
      }
    }
    return m_data[m_dataOffset++];
  }
public:
  uint8_t m_buffer[32768];
  uint32_t m_data[16384];
  size_t m_dataOffset, m_dataSize;
  uint32_t m_v;
};


/* End of fast IO*/

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
  if(lo == 0) return 0.0;
  return lo/10.;
}

int main() {
  FastInput obj;
  t = obj.ReadNext();
  while(t--) {
    n = obj.ReadNext();
    m = obj.ReadNext();

    REP(i, m) h[i] = obj.ReadNext()*10;
    sort(h, h+m);

    printf("%.1lf\n", binarySearch());
  }
}
