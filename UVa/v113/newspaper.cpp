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
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

char s[10010];
int pay[256];

int main() {
    int t, k, p, m, sum, cents;
    sscanf(gets(s), "%d", &t);

    while(t--) {
        sscanf(gets(s), "%d", &k);

        memset(pay, 0, sizeof pay);
        while(k--) {
            char ch;
            sscanf(gets(s), "%c %d", &ch, &p);
            pay[ch] = p;
        }

        sscanf(gets(s), "%d", &m);
        sum = 0;
        while(m--) {
            gets(s);
            for(int i = 0; s[i]; i++)
                sum += pay[s[i]];
        }
        cents = sum % 100;
        sum /= 100;
        printf("%d.", sum);
        if(cents < 10) printf("0");
        printf("%d$\n", cents);
    }
    return 0;
}

