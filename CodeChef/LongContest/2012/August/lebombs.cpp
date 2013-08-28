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

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXN = 1111;

bool explotions[MAXN];
char buildings[MAXN];

int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);

        scanf("%s", buildings);

        memset(explotions, false, sizeof(explotions));
        int cnt = n;

        for(int k = 1; k < n-1; k++) {
            if(buildings[k] == '1') {
                for(int j = k-1; j <= k+1; j++) {
                    if(!explotions[j])
                        cnt--;
                    explotions[j] = true;
                }
            }
        }
        if(buildings[0] == '1') {
            for(int j = 0; j <= 1 && j < n; j++) {
                if(!explotions[j])
                    cnt--;
                explotions[j] = true;
            }
        }
        if(buildings[n-1] == '1') {
            for(int j = n-2; j >= 0 && j <= n-1; j++) {
                if(!explotions[j])
                        cnt--;
                explotions[j] = true;
            }
        }
        printf("%d\n", cnt);
    }
}

