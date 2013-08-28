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

#define D(x) cerr << #x << " = " << x << endl

using namespace std;

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


int hand[3];

int main() {
  FastInput obj;
	while(true) {
		hand[0] = obj.ReadNext(); 
    hand[1] = obj.ReadNext(); 
    hand[2] = obj.ReadNext();
		if((hand[0]|hand[1]|hand[2]) == 0) return 0;
		sort(hand, hand+3);
		if(hand[0] == hand[1] && hand[1] == hand[2]) { // set
			if(hand[0] == 13) puts("*");
			else printf("%d %d %d\n", (hand[2]+1), (hand[2]+1), (hand[2]+1));
		}
		else if(hand[0] == hand[1]) { // pair 1
			hand[2]++;
			if(hand[2] > 13) {
				hand[0]++, hand[1]++, hand[2] = 1;
			}
			sort(hand, hand+3);
			printf("%d %d %d\n", hand[0], hand[1], hand[2]);
		}
		else if(hand[1] == hand[2]) { // pair 2
			if(hand[0] == 12 && hand[1] == 13) {
				puts("1 1 1");
				continue;
			}
			do { 
				hand[0]++; 
				if(hand[0] > 13) {
					hand[0] = 1, hand[1]++, hand[2]++;
					break;
				}
			} while(hand[0] == hand[1]);
			sort(hand, hand+3);
			printf("%d %d %d\n", hand[0], hand[1], hand[2]);
		}
		else puts("1 1 2");
	}
}
