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

map<string, string> chefc;
map<string, int> chefv, countv;
char name[20], country[20];

void print_best(const map<string, int>& v) {
    int best = -1;
    string ans;

    FOREACH(it, v) {
        if(it->second > best) {
            best = it->second;
            ans = it->first;
        }
    }
    puts(ans.c_str());
}

int main() {
    int n, m, i;
    scanf("%d%d", &n, &m);

    for(i = 0; i < n; i++) {
        scanf("%s%s", name, country);
        chefc[name] = country;
    }

    for(i = 0; i < m; i++) {
        scanf("%s", name);
        chefv[name]++;
        countv[chefc[name]]++;
    }

    print_best(countv);
    print_best(chefv);

    return 0;
}

