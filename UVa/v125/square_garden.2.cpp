#include <cstdio>
#include <cstdlib>
#include <cctype>

#define max(x,y) (((x) > (y))? (x) : (y))

namespace IO {
#define MAXBUFF (1<<18)
  char buffer[MAXBUFF], *p = buffer+MAXBUFF;

  inline char read_char() {
    if( p == buffer+MAXBUFF ) {
      fread( buffer, 1, MAXBUFF, stdin );
      p = buffer;
    }
    return *p++;
  }

  inline int read_signed_int() {
    char c;
    while( !isdigit(c = read_char()) and c != '-' );
    int sign = 1;
    if (c == '-') sign = -1, c = read_char();
    int ret = c-'0';
    while( isdigit(c = read_char()) ) ret = ret * 10 + c-'0';
    return ret * sign;
  }

  inline int ruint() {
    char c;
    while( !isdigit(c = read_char()) );
    int ret = c-'0';
    while( isdigit(c = read_char()) ) ret = ret * 10 + c-'0';
    return ret;
  }

  inline long long rull() {
    char c;
    while( !isdigit(c = read_char()) );
    long long ret = c-'0';
    while( isdigit(c = read_char()) ) ret = ret * 10 + c-'0';
    return ret;
  }
}

long long odd1(long long L, long long N) {
  if (L == 1)
    return (N == 1)? 4 : 0;

  long long total = ((L >> 1) * ((L >> 1) + 1)) << 1;
  long long ret = total << 2;

  if (N > total) {
    if (N > total + 4) {
      total += 4;
      long long res = L - (L >> 1) - 2; // avail sq
      if (N > total + (res << 2)) {
        N = N - total - (res << 2);
        ret = ret - (res << 3) - (N << 2);
      }
      else {
        N -= total;
        ret -= (N << 1);
      }
    }
  }
  else return N << 2;
  return ret;
}

long long odd2(long long L, long long N) {
  long long total = (((L >> 1) * ((L >> 1) + 1)) << 1) + 1;
  long long ret = total << 2;

  if (N > total) {
    long long res = (L >> 1);
    if (N > total + (res << 2)) {
      N = N - total - (res << 2);
      ret = ret - (res << 3) - (N << 2);
    }
    else {
      N -= total;
      ret -= (N << 1);
    }
  }
  else return N << 2;

  return ret;
}

long long even(long long L, long long N) {
  long long total = (L >> 1) * L;
  long long ret = total << 2;

  if (N > total) {
    if (N > total + 2) {
      total += 2;
      long long res = L - (L >> 1) - 1;
      if (N > total + (res << 2)) {
        N = N - total - (res << 2);
        ret = ret - (res << 3) - (N << 2);
      }
      else {
        N -= total;
        ret -= (N << 1);
      }
    }
  }
  else return N << 2;

  return ret;
}

int main() {
  while (true) {
    int L = IO::ruint();
    long long N = IO::rull();
    if (!(L|N)) break;
    printf("%lld\n", ((L & 1)? max(odd1(L,N), odd2(L,N)) : even(L,N)));
  }
  return 0;
}
