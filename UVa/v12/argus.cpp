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

int times[3010];

int main() {
    ios_base::sync_with_stdio(false);

    string op;
    set< pair<int, int> > heap;

    while(cin >> op) {
        if(op[0] == '#') break;
        int id, p;
        cin >> id >> p;
        times[id] = p;
        heap.insert( make_pair(p, id) );
    }

    int k;
    cin >> k;

    for(int i = 0; i < k; i++) {
        set< pair<int,int> >::iterator it = heap.begin();
        heap.erase(it);
        cout << it->second << endl;
        int new_period = it->first + times[it->second];
        heap.insert(make_pair(new_period, it->second));
    }

    return 0;
}

