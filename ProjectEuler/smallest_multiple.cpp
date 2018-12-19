#include <iostream>
#include <algorithm>

using namespace std;

long long lcm(long long a, long long b) {
  return a*b / __gcd(a,b);
}

int main() {
  long long l = lcm(1, 2);
  for(long long i = 3; i <= 20; i++) {
    l = lcm(l, i);
  }
  cout << l << endl;
  return 0;
}
