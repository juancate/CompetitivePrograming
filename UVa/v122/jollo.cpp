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

int A[3];

bool solve(int x, int y, int z) {
    vector<int> B(3);
    B[0] = x; B[1] = y; B[2] = z;
    sort(ALL(B));

    bool win = true;

    do {
        int cnt = 0;
        for(int i = 0; i < 3; i++)
            if(B[i] > A[i])
                cnt++;
        win &= (cnt >= 2);
    } while(next_permutation(ALL(B)));
    return win;
}

int main() {
    int a, b, c, x, y, z;
    while(scanf("%d%d%d%d%d", &a, &b, &c, &x, &y)) {
        if(!(a|b|c|x|y)) break;

        vector<bool> used(53, false);
        used[a] = used[b] = used[c] = used[x] = used[y] = true;
        A[0] = a; A[1] = b; A[2] = c;
        sort(A, A+3);
        bool win = false;

        for(z = 1; z <= 52; z++) {
            if(used[z]) continue;
            if(solve(x, y, z)) {
                win = true;
                break;
            }
        }
        if(!win) z = -1;
        printf("%d\n", z);
    }
    return 0;
}

