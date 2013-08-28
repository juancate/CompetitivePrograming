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
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

/* IO Fast */

int ascii_value[256] = {
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
};


class _in
{
public:
  _in()
  {
    buffend = buff;
    ptr = buffend;
  }
  
  void SkipLine()
  {
    while (ptr < buffend && *ptr == '\n') ptr++;
    if (ptr >= buffend)
      {
        if (!_ReadInput())
          return ;
        while (ptr < buffend && *ptr == '\n') ptr++;
      }
  }
 
  void SkipWhiteSpace()
  {
    while (ptr < buffend && (*ptr == ' ' || *ptr == '\r' || *ptr == '\n' || *ptr == '\t')) ptr++;
    if (ptr >= buffend)
      {
        if (!_ReadInput())
          return ;
        while (ptr < buffend && (*ptr == ' ' || *ptr == '\r' || *ptr == '\n' || *ptr == '\t')) ptr++;
      }
  }
 
  char ReadNextChar(bool skip = true)
  {
    if (skip) SkipWhiteSpace();
    if (ptr >= buffend)
      {
        if (!_ReadInput())
          return 0;
      }
    return *(ptr++);
  }
 
  void ReadString(char * str)
  {
    SkipWhiteSpace();
    
    while (ptr < buffend && *ptr && *ptr != ' ' && *ptr != '\n' && *ptr != '\t')
      *(str++) = *(ptr++);
    
    while (ptr >= buffend)
      {
        if (!_ReadInput())
          return ;
        
        while (ptr < buffend && *ptr && *ptr != ' ' && *ptr != '\n' && *ptr != '\t')
          *(str++) = *(ptr++);
      }
 
    *str = 0;
  }
 
  int ReadNextInt()
  {
    int v = 0;
    SkipWhiteSpace();
    
    {
      int c = ascii_value[ *(ptr++) ];
      while (c >= 0 && ptr < buffend)
        {
          v = v * 10 + c;
          c = ascii_value[ *(ptr++) ];
        }
      if (c >= 0)
        {
          v = v * 10 + c;
          if (ptr >= buffend)
            {
              if (_ReadInput())
                {
                  c = ascii_value[ *(ptr++) ];
                  while (c >= 0 && ptr < buffend)
                    {
                      v = v * 10 + c;
                      c = ascii_value[ *(ptr++) ];
                    }
                  if (c >= 0)
                    v = v * 10 + c;
                }
            }
        }
    }
    return v;
  }
 
  unsigned int ReadNextUInt()
  {
    unsigned int v = 0;
    SkipWhiteSpace();
    
    {
      unsigned int c = ascii_value[ *(ptr++) ];
      while (c < 10 && ptr < buffend)
        {
          v = v * 10 + c;
          c = ascii_value[ *(ptr++) ];
        }
      if (c < 10)
        {
          v = v * 10 + c;
          if (ptr >= buffend)
            {
              if (_ReadInput())
                {
                  c = ascii_value[ *(ptr++) ];
                  while (c < 10 && ptr < buffend)
                    {
                      v = v * 10 + c;
                      c = ascii_value[ *(ptr++) ];
                    }
                  if (c < 10)
                    v = v * 10 + c;
                }
            }
        }
    }
    return v;
  }
 
  uint64_t ReadNextUInt64()
  {
    uint64_t v = 0;
    SkipWhiteSpace();
    
    {
      uint64_t c = ascii_value[ *(ptr++) ];
      while (c < 10 && ptr < buffend)
        {
          v = v * 10 + c;
          c = ascii_value[ *(ptr++) ];
        }
      if (c < 10)
        {
          v = v * 10 + c;
          if (ptr >= buffend)
            {
              if (_ReadInput())
                {
                  c = ascii_value[ *(ptr++) ];
                  while (c < 10 && ptr < buffend)
                    {
                      v = v * 10 + c;
                      c = ascii_value[ *(ptr++) ];
                    }
                  if (c < 10)
                    v = v * 10 + c;
                }
            }
        }
    }
    return v;
  }
 
  int ReadNextFixedFloat(int digit)
  {
    int v = ReadNextInt();
    if (ptr > buff && *(ptr-1) == '.')
      {
        int c = ascii_value[ *(ptr++) ];
        while (c >= 0 && ptr < buffend)
          {
            if (digit-- > 0)
              v = v * 10 + c;
            c = ascii_value[ *(ptr++) ];
          }
        if (c >= 0)
          {
            if (digit-- > 0)
              v = v * 10 + c;
            if (ptr >= buffend)
              {
                if (_ReadInput())
                  {
                    c = ascii_value[ *(ptr++) ];
                    while (c >= 0 && ptr < buffend)
                      {
                        if (digit-- > 0)
                          v = v * 10 + c;
                        c = ascii_value[ *(ptr++) ];
                      }
                    if (c >= 0)
                      if (digit-- > 0)
                        v = v * 10 + c;
                  }
              }
          }
      }
    
    while (digit-- > 0)
      v *= 10;
    
    return v;
  }
 
protected:
  char buff[0x80000]; // 32768 / 0x8000 0x80000
  char * buffend, * ptr;
  
  bool _ReadInput()
  {
    int len = read(0, buff, sizeof(buff));
    if (len <= 0) return false;
    buffend = buff+len;
    ptr = buff;
    return true;
  }
} in;

class _out
{
public:
  _out()
  {
    buffend = buff + sizeof(buff);
    ptr = buff;
  }
  ~_out()
  {
    Flush();
  }
  
  void WriteChar(char c)
  {
    if (ptr+1 >= buffend)
      Flush();
    
    *(ptr++) = c;
  }
  
  void WriteString(char * str)
  {
    while (*str && ptr < buffend)
      *(ptr++) = *(str++);
    
    if (ptr >= buffend)
      Flush();
    
    while (*str) // assume that buffer is large enough
      *(ptr++) = *(str++);
  }
  
  void WriteUInt(unsigned int value, char sep)
  {
    if (ptr+10+1 >= buffend)
      Flush();
    
    char txt[16];
    char * p = txt;
    int len = 0;
    do
      {
        *(p++) = (value%10) + '0'; len++;
        value /= 10;
      } while (value > 0);
 
    while (len--)
      (*ptr++) = *(--p);
 
    *(ptr++) = sep;
  }
 
  void WriteUIntLastDigit(unsigned int value, int digit, char sep)
  {
    if (ptr+10+1 >= buffend)
      Flush();
 
    char txt[16];
    char * p = txt;
    int len = 0;
    do
      {
        *(p++) = (value%10) + '0'; len++;
        value /= 10;
      } while (--digit && value > 0);
 
    while (len--)
      (*ptr++) = *(--p);
 
    *(ptr++) = sep;
  }
 
  void WriteFloat(float value, int prec, char sep)
  {
    if (ptr+10+prec+1 >= buffend)
      Flush();
 
    int iv = (int)value;
 
    char txt[16];
    char * p = txt;
    int len = 0;
    do
      {
        *(p++) = (iv%10) + '0'; len++;
        iv /= 10;
      } while (iv > 0);
 
    while (len--)
      (*ptr++) = *(--p);
    
    if (prec > 0)
      {
        *(ptr++) = '.';
        value -= (float)(int)value;
        while (prec--)
          {
            value *= 10.f;
            iv = (int)value;
            *(ptr++) = (iv%10) + '0';
          }
      }
 
    *(ptr++) = sep;
  }
 
  void WriteDouble(double value, int prec, char sep)
  {
    if (ptr+10+prec+1 >= buffend)
      Flush();
    
    int iv = (int)value;
    
    char txt[16];
    char * p = txt;
    int len = 0;
    do
      {
        *(p++) = (iv%10) + '0'; len++;
        iv /= 10;
      } while (iv > 0);
 
    while (len--)
      (*ptr++) = *(--p);
    
    if (prec > 0)
      {
        *(ptr++) = '.';
        value -= (double)(int)value;
        while (prec--)
          {
            value *= 10.f;
            iv = (int)value;
            *(ptr++) = (iv%10) + '0';
          }
      }
 
    *(ptr++) = sep;
  }
 
  void Flush()
  {
    if (ptr-buff > 0)
      {
        write(1, buff, (int)(ptr-buff));
        ptr = buff;
      }
  }
 
protected:
 
  char buff[32768];
  char * buffend, * ptr;
} out;


/* END IO Fast*/


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
  if(lo == 0) return 0.0;
  return lo/10.;
}

int main() {
  t = in.ReadNextInt();
  while(t--) {
    n = in.ReadNextInt();
    m = in.ReadNextInt();

    REP(i, m) h[i] = in.ReadNextInt() * 10;
    sort(h, h+m);
    
    out.WriteDouble(binarySearch(), 1, '\n');
  }
}
