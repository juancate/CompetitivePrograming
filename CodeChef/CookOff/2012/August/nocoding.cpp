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

const int MAXN = 1111;

char word[MAXN];

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s", word);
        int reg = word[0] - 'a';

        int n = strlen(word);
        int oper = 2;

        REP(i, 1, n) {
            if(word[i] - 'a' < reg) {
                oper += 25 - reg + 1;
                reg = word[i] - 'a';
                oper += reg;
            } else {
                oper += (word[i] - 'a') - reg;
                reg = word[i] - 'a';
            }
            oper++; //print
        }

        if(oper <= 11*n)
            puts("YES");
        else
            puts("NO");
    }
}

