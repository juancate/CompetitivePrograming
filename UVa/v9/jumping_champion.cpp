#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
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

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

// Algorithm: Number theory - Sieve

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int maxp = 1000001;
bitset<1000010> criba;
vector<int> primes, differences;
int champion[200];

void sieve() {
  criba.set();
  criba[0] = criba[1] = false;

  for(int64 i = 2; i <= maxp; i++) {
    if(criba[i]) {
      for(int64 j = i*i; j <= maxp; j += i)
	criba[j] = false;
      primes.push_back((int)i);
    }
  }
  sort(ALL(primes));
}

int main() {
  sieve();

  int t; scanf("%d", &t);

  while(t--) {
    int lower, upper;
    scanf("%d%d", &lower, &upper);

    int start = int(lower_bound(ALL(primes), lower) - primes.begin());
    int end = int(lower_bound(ALL(primes), upper) - primes.begin());

    if(end >= primes.size() || primes[end] > upper) end--;

    int ans = 0, num = -1, max_val = -1;
    memset(champion, 0, sizeof(champion));

    for(int i = start+1; i <= end; i++) {
      int current = primes[i] - primes[i-1];
      champion[current]++;

      if(champion[current] > ans) {
	ans = champion[current];
	num = current;
      }

      if(max_val < current)
	max_val = current;
    }

    int count_champions = 0;

    for(int i = 0; i <= max_val; i++) {
      if(champion[i] == ans)
	count_champions++;
    }

    if(max_val == -1 || count_champions > 1)
      puts("No jumping champion");
    else
      printf("The jumping champion is %d\n", num);
  }
}

