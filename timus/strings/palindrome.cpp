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

int n;
char word[1010];

bool is_palindrome(int i, int j) {
    while(i < j) {
        if(word[i] != word[j])
            return false;
        i++; j--;
    }
    return true;
}

int main() {
    while(~scanf("%s", word)) {
        n = (int)strlen(word);
        int start = 0, end = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                if(i-j+1 > end-start+1) {
                    if(is_palindrome(j, i)) {
                        start = j;
                        end = i;
                    }
                }
            }
        }

        for(int i = start; i <= end; i++)
            printf("%c", word[i]);
        printf("\n");
    }
    return 0;
}

