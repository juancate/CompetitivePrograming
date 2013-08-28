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

int n;
vector<int> numbers;

bool check() {
    int first = numbers[0];

    REP(i, 1, n)
        if(numbers[i] != first)
            return false;

    return true;
}

int main() {
    while(~scanf("%d", &n) && n) {
        numbers.assign(n, 0);

        REP(i, 0, n)
            scanf("%d", &numbers[i]);

        int blows = 0;
        while(!check()) {
            vector<int> current(n);

            for(int i = 1; i < n; i++) {
                current[i] = (numbers[i-1] >> 1) + (numbers[i] >> 1);
                if(current[i] & 1)
                    current[i]++;
            }

            current[0] = (numbers[n-1] >> 1) + (numbers[0] >> 1);
            if(current[0] & 1)
                current[0]++;

            numbers = current;

            blows++;
        }

        printf("%d %d\n", blows, numbers[0]);
    }
}

