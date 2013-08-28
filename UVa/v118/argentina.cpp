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

struct player {
    int offense, defense;
    string name;

    player(string n = "", int o = 0, int d = 0) {
        name = n;
        offense = o;
        defense = d;
    }

    bool operator<(const player& b) const {
        if(offense == b.offense) {
            if(defense == b.defense)
                return name < b.name;
            return defense < b.defense;
        }
        return offense > b.offense;
    }
} team[10];

bool name_cmp(const player& a, const player& b) {
    return a.name < b.name;
}

char player_name[111];

int main() {
    int t; scanf("%d", &t);

    REP(case_id, 1, t+1) {
        REP(i, 0, 10) {
            int o, d; scanf("%s%d%d", player_name, &o, &d);
            team[i] = player(player_name, o, d);
        }

        sort(team, team + 10);

        sort(team, team + 5, name_cmp);
        sort(team + 5, team + 10, name_cmp);

        printf("Case %d:\n", case_id);
        printf("(");
        REP(i, 0, 5) {
            if(i) printf(", ");
            printf("%s", team[i].name.c_str());
        }
        printf(")\n");

        printf("(");
        REP(i, 5, 10) {
            if(i > 5) printf(", ");
            printf("%s", team[i].name.c_str());
        }
        printf(")\n");
    }
}

