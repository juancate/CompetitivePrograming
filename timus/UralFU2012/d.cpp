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

int x[251], y[251];
char plane[202][202];

void init_plane() {
    memset(plane, '.', sizeof plane);

    for(int i = 0; i < 202; i++) {
        plane[100][i] = '-';
        plane[i][100] = '|';
    }

    plane[100][100] = '+';
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d%d", &x[i], &y[i]);

    init_plane();

    int min_x, min_y, max_x, max_y;
    min_x = min_y = max_x = max_y = 100;

    for(int i = 0; i < n; i++) {
        int current_x = x[i] + 100;
        int current_y = 100 - y[i];

        plane[current_y][current_x] = '*';

        min_x = min(min_x, current_x);
        max_x = max(max_x, current_x);
        min_y = min(min_y, current_y);
        max_y = max(max_y, current_y);
    }

    for(int i = min_y; i <= max_y; i++) {
        for(int j = min_x; j <= max_x; j++)
            printf("%c", plane[i][j]);
        printf("\n");
    }
}

