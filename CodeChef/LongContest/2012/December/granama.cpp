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

int a[26], b[26];
bool ingredientsA[26], ingredientsB[26];
char recipeA[1010], recipeB[1010];

bool granama() {
    for(int i = 0; i < 26; i++) {
        if(a[i] != b[i])
            return false;
    }
    return true;
}

bool isGranama() {
    for(int i = 0; i < 26; i++) {
        if(ingredientsA[i] != ingredientsB[i])
            return false;
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%s%s", recipeA, recipeB);

        int n = strlen(recipeA);
        int m = strlen(recipeB);

        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);

        memset(ingredientsA, 0, sizeof ingredientsA);
        memset(ingredientsB, 0, sizeof ingredientsB);

        for(int i = 0; i < n; i++) {
            a[recipeA[i] - 'a']++;
            ingredientsA[recipeA[i] - 'a'] = true;
        }
        for(int i = 0; i < m; i++) {
            b[recipeB[i] - 'a']++;
            ingredientsB[recipeB[i] - 'a'] = true;
        }

        bool isG = isGranama();
        bool g = granama();

        puts(((isG && g) || (!isG && !g))? "YES" : "NO");
    }
}

