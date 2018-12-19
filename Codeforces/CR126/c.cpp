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
#include <set>
#include <map>
#include <algorithm>

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

#ifdef L
#include "../../debug.h"
#endif

string s1[10], s2[10], score[10];
map<string, int> mp;
string name[10];
int a[10][10];

bool better(int x, int y) {
    int score_x = 0, score_y = 0, goals_x = 0, goals_y = 0, missed_x = 0, missed_y = 0;

    REP(i, 0, 4) if(i != x) {
        if(a[x][i] > a[i][x]) score_x += 3;
        else if(a[x][i] == a[i][x]) score_x++;
        goals_x += a[x][i];
        missed_x += a[i][x];
    }

    REP(i, 0, 4) if(i != y) {
        if(a[y][i] > a[i][y]) score_y += 3;
        else if(a[y][i] == a[i][y]) score_y++;
        goals_y += a[y][i];
        missed_y += a[i][y];
    }

    if(score_x != score_y) return score_x > score_y;
    if(goals_x - missed_x != goals_y - missed_y)
        return (goals_x - missed_x > goals_y - missed_y);
    if(goals_x != goals_y) return goals_x > goals_y;
    return x < y;
}

bool check(int x, int y) {
    int b = mp["BERLAND"];
    int c;
    REP(i, 0,4) if(i != b && a[b][i] == -1) c = i;

    a[b][c] = x, a[c][b] = y;

    int rank = 1;
    REP(i, 0, 4) if(i != b && better(i, b)) rank++;

    a[b][c] = a[c][b] = -1;

    return (rank <= 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    REP(i, 0, 5) cin >> s1[i] >> s2[i] >> score[i];

    REP(i, 0, 5) mp[s1[i]] = mp[s2[i]] = 0;

    int k = 0;
    FOREACH(it, mp) {
        it->second = k;
        name[k] = it->first;
        k++;
    }

    REP(i, 0, 4) REP(j, 0, 4) a[i][j] = -1;

    REP(i, 0, 5) {
        int x = mp[s1[i]], y = mp[s2[i]];
        REP(j, 0, score[i].size()) if(score[i][j] == ':') score[i][j] = ' ';
        stringstream ss(score[i]);
        ss >> a[x][y] >> a[y][x];
    }

    REP(d, 1, 100) REP(i, 0, 100) {
        int j = d + i;
        if(check(j, i)) {
            cout << j << ':' << i << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}

