#include <iostream>
#include <vector>

using namespace std;

long long factor(long long q) {
  long long p = 2;
  vector<long long> f;
  while(p * p <= q) {
    if(q % p == 0) {
      while(q % p == 0) q /= p;
      f.push_back(p);
    }
    p++;
  }
  if(q > 1)
    f.push_back(q);
  return f.back();
}

int main() {
  long long x = 600851475143LL;
  cout << factor(x) << endl;
  return 0;
}
