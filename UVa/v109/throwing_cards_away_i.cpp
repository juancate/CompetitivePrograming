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

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;


int main() {
    int n;

    while(scanf("%d", &n) && n) {
        deque<int> deck;
        vector<int> throwed;

        for(int i = 1; i <= n; i++)
            deck.push_back(i);

        while(deck.size() >= 2) {
            throwed.push_back(deck[0]);
            deck.pop_front();
            deck.push_back(deck[0]);
            deck.pop_front();
        }

        printf("Discarded cards:");
        for(int i = 0; i < (int)throwed.size(); i++) {
            if(i) printf(", ");
            else printf(" ");
            printf("%d", throwed[i]);
        }
        printf("\nRemaining card: %d\n", deck[0]);
    }
}

