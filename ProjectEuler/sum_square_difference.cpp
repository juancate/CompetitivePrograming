#include <iostream>

using namespace std;

int main() {
  long long sq = 0;
  for(long long i = 1; i <= 100; i++)
    sq += i*i;
  long long sum = 50*101;
  sum *= sum;
  cout << (sum - sq) << endl;
  return 0;
}
