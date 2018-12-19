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

// Problem: 11569 - Lovely Hint
// Algorithm: Backtracking

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

string str;
char word[300], arr[30];
int ways[30];

void backtracking(int at, int pos) {
    if(pos == str.size()) {
        ways[at]++;
        return;
    }

    REP(i, pos, str.size()) {
        if(at == 0) {
            arr[at] = str[i];
            backtracking(at + 1, pos + 1);
        } else {
            int p = (arr[at - 1] - 'A' + 1) * 5;
            int q = (str[i] - 'A' + 1) * 4;

            if(p <= q) {
                arr[at] = str[i];
                backtracking(at + 1, i + 1);
            }
        }
    }
    ways[at]++;
}

int main() {
    int t; scanf("%d\n", &t);

    while(t--) {
        gets(word);

        str.clear();

        for(int i = 0; word[i]; i++) {
            if(isupper(word[i]))
                str += word[i];
        }

        sort(ALL(str));
        str.resize(unique(ALL(str)) - str.begin());

        memset(ways, 0, sizeof(ways));

        backtracking(0, 0);

        int ans = 26;

        for(int i = 26; i >= 0; i--) {
            if(ways[i] != 0) {
                ans = i;
                break;
            }
        }

        printf("%d %d\n", ans, ways[ans]);
    }
}

