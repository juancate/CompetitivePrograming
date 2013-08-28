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

const int MAXP = 31623;
bool criba[MAXP+10];
vector<int> primes;
int T, N, M;

void generatePrimes() {
  memset(criba, false, sizeof(criba));
  criba[0] = criba[1] = true;
  int raiz = (int)sqrt(MAXP);
  for(int i = 3; i <= raiz; i+=2) {
    if(!criba[i])
      for(int j = i*i; j <= MAXP; j += i)
        criba[j] = true;
  }
  primes.push_back(2);
  primes.push_back(3);
  
  for(int i = 5, j = 7; i <= MAXP; i+=6, j+=6){
    if(!criba[i]) 
      primes.push_back(i);
    if(!criba[j]) 
      primes.push_back(j);
  }
}

int main() {
  scanf("%d", &T);
  generatePrimes();
  sort(ALL(primes));
  while(T--) {
    scanf("%d %d", &M, &N);
    vector<int>::iterator start, end;
    start = lower_bound(ALL(primes), M);
    end = upper_bound(ALL(primes), N);
    while(start != end) {
      printf("%d\n", *start);
      start++;
    }
    //while(*start <= N and start != primes.end()) printf("%d\n", *start++);
    if(T) puts("");
  }
}

