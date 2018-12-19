#include <iostream>

using namespace std;

int main() {
  long long a = 1, b = 2;
  long long sum = 2;

  long long c = a + b;
  while(c <= 4000000) {
    if(!(c & 1)) sum += c;
    a = b; b = c;
    c = a + b;
  }
  cout << sum << endl;
  return 0;
}
