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

int64 sieve_size;
bitset<10000010> bs;
vector<int> primes;

void sieve(int64 upperBound) {
    sieve_size = upperBound + 1;
    bs.set();

    bs[0] = bs[1] = 0;

    for(int64 i = 2; i <= sieve_size; i++) {
        if(bs[i]) {
            for(int64 j = i * i; j <= sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i);
        }
    }
}

bool isPrime(int64 n) {
    if(n <= sieve_size) return bs[n];

    for(int i = 0; i < (int)primes.size(); i++)
        if(n % primes[i] == 0) return false;

    return true;
}

int main() {
    int T, M, N;

    scanf("%d", &T);
    sieve(31622);
    /*
    REP(i, primes.size())
        cerr << primes[i] << endl;
    */
    while(T--) {
        scanf("%d %d", &M, &N);
        for(int i = M; i <= N; i++) {
            if(isPrime(i)) printf("%d\n", i);
        }

        if(T) puts("");
    }
}

