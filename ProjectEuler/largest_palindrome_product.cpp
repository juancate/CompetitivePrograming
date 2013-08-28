#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_pal(int x) {
  stringstream ss;
  ss << x;
  string s = ss.str();
  string t = s;
  reverse(t.begin(), t.end());
  return s == t;
}

int main() {
  int best = 0;
  for(int i = 100; i < 1000; i++) {
    for(int j = 100; j < 1000; j++) {
      int prod = i*j;
      if(is_pal(prod)) {
        best = max(prod, best);
      }
    }
  }
  cout << best << endl;
  return 0;
}

