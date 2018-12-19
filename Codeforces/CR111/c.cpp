#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

#define INF 1<<30
#define EPS 1e-13

using namespace std;

typedef long long int64;

#define long int64

int main() {
  ios_base::sync_with_stdio(false);
  long n, k;
  cin >> n >> k;
  vector<long> numbers(n);
  REP(i,n) cin >> numbers[i];
  int id = 0;
  int col = 0;
  
  for(long i = 1; i <= n; i++) if(i*i >= k) {
      id = (int)i;
      break;
    }
  id--;
  k = k - (id*id);
  sort(ALL(numbers));
  D(k); D(id);
  cout << numbers[id] << " " << numbers[int(k) - 1] << endl;
}

#undef long

