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

// Problem: Glass Beads
// Algorithm: Minimal Representation

char line[10010];

int minExp(const string& str) {
    string s = str + str;

    int i = 0, j = 1, k = 0, len = (int)str.size();

    while(i < len && j < len) {
        if(s[i+k] == s[j+k]) {
            k++;
            if(k == len) break;
        }
        else {
            if(s[i+k] > s[j+k]) {
                i = i+k+1;
                if(i <= j)
                    i = j+1;
            }
            else if(s[i+k] < s[j+k]) {
                j = j+k+1;
                if(j <= i)
                    j = i+1;
            }
            k = 0;
        }
    }

    return min(i, j);
}

int main() {
    int t; sscanf(gets(line), "%d", &t);

    while(t--) {
        gets(line);

        int ans = minExp(line) + 1;

        printf("%d\n", ans);
    }
}

