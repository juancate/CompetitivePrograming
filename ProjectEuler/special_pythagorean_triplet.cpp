#include <iostream>
#include <cmath>

using namespace std;

int main() {
  for(int a = 0; a <= 1000; a++) {
    for(int b = a+1; b <= 1000; b++) {
      int c = (int)sqrt(double(a*a + b*b));
      if(c*c == a*a + b*b) {
        if(a < b && b < c && a+b+c == 1000) {
          cout << a << " " << b << " " << c << endl;
          cout << (a*b*c) << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}
