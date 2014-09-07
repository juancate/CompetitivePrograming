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

bool used[256];
char s[512];

int main() {
    int t;
    sscanf(gets(s), "%d", &t);
    while(t--) {
        gets(s);
        memset(used, false, sizeof used);
        for(int i = 0; s[i]; i++)
            if(isalpha(s[i]))
                used[tolower(s[i])] = true;
        bool ok = false;

        for(int i = 'a'; i <= 'z'; i++)
            if(!used[i]) {
                printf("%c", i);
                ok = true;
            }

        if(!ok) printf("~");
        printf("\n");
    }

    return 0;
}
