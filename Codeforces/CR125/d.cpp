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

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define mp(x,y) make_pair(x, y)

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

int n, k;
string walls[2];
bool visited[2][200000+10];

bool valid(int w, int y, int water) {
    if(y < 0) return false;
    if(y < water) return false;
    if(visited[w][y]) return false;
    if(y >= n) return true;
    if(walls[w][y] == 'X') return false;

    return true;
}

bool search() {
    memset(visited, false, sizeof(visited));

    queue< pair<int, pair<int, int> > > Q;

    if(valid(0, 0, 0)) {
        Q.push(mp(0, mp(0, 0)));
        visited[0][0] = true;
    }

    while(!Q.empty()) {
        int w = Q.front().first;
        int y = Q.front().second.first;
        int water = Q.front().second.second;
        Q.pop();

        if(y + k >= n) return true;

        if(valid(w, y-1, water+1)) {
            Q.push(mp(w, mp(y-1, water+1)));
            visited[w][y-1] = true;
        }

        if(valid(w, y+1, water+1)) {
            Q.push(mp(w, mp(y+1, water+1)));
            visited[w][y+1] = true;
        }

        int nw = w^1;

        if(valid(nw, y + k, water+1)) {
            Q.push(mp(nw, mp(y+k, water+1)));
            visited[nw][y+k] = true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> walls[0] >> walls[1];
    cout << (search()? "YES" : "NO") << endl;
}

