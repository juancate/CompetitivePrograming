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

typedef long long ll;

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


int N, m, k;
ll total;
int p[600];

bool check(ll val) {
	int j = 1;
	ll sum = 0;

	for(int i = 0; i < m; i++) {
    if(p[i] > val) return false; // necesito un val mas grande
		if(sum + p[i] > val) {
			sum = p[i];
			j++;
		} else {
			sum += p[i];
		}
	}
  return (j <= k); // true: necesito mas libros. false: necesito menos.
}

ll binarySearch(ll low, ll end) {
	ll lo = low, hi = end, mid;
	while(lo < hi) {
		mid = lo + (hi - lo)/2;
    bool ret = check(mid);

		if(ret)
			hi = mid;
		else
			lo = mid+1;
	}
	return lo;
}

int main() {
  FastInput obj;
  N = obj.ReadNext();
	while(N--) {
    m = obj.ReadNext();
    k = obj.ReadNext();

		total = 0;
		for(int i = 0; i < m; i++) {
			p[i] = obj.ReadNext();
			total += p[i];
		}

		ll ans = binarySearch(0, total);
    
		ll subsum = 0;

    vector<int> scribbers[k];
    
    for(int i = m-1, j = k-1; i >= 0 and j >= 0; i--) {
      if(subsum + p[i] <= ans and (i >= j)) {
        subsum += p[i];
      }
      else {
        subsum = p[i];
        j--;
      }
      scribbers[j].push_back(p[i]);      
    }
    
    for(int i = 0; i < k; i++) {
      int sz = scribbers[i].size();
      for(int j = sz - 1; j >= 0; j--) {
        if(j < sz - 1) printf(" ");
        printf("%d", scribbers[i][j]);
      }
      if(i < k-1) printf(" / ");
    }
		puts("");
	}
}
