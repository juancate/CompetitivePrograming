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

int rows, cols;
vector<string> world;
vector< vector<bool> > visited;

static int dr[] = {0, 1, 0, -1};
static int dc[] = {1, 0, -1, 0};

bool valid(int nr, int nc) {
    return (nr >= 0 && nr <= rows-1 && nc >= 0 && nc <= cols-1);
}

void dfs(int r, int c, char s) {
    if(visited[r][c]) return;

    visited[r][c] = true;

    for(int k = 0; k < 4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if(valid(nr, nc) && !visited[nr][nc] && world[nr][nc] == s) {
            dfs(nr, nc, s);
        }
    }
}

bool cmp(const pair<char, int>& a, const pair<char, int>& b) {
    if(a.second == b.second)
        return a.first < b.first;

    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);

    int t; cin >> t;

    for(int case_id = 1; case_id <= t; case_id++) {
        cin >> rows >> cols;

        world.resize(rows);
        for(int i = 0; i < rows; i++)
            cin >> world[i];

        visited.assign(rows, vector<bool>(cols, false));
        vector<int> cnt(26, 0);

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(!visited[i][j]) {
                    char ch = world[i][j];
                    dfs(i, j, ch);
                    cnt[ch-'a']++;
                }
            }
        }

        vector< pair<char, int> > ans;
        for(int i = 0; i < (int)cnt.size(); i++)
            if(cnt[i] > 0)
                ans.push_back( make_pair(i+'a', cnt[i]) );

        sort(ALL(ans), cmp);

        cout << "World #" << case_id << endl;
        for(int i = 0; i < (int)ans.size(); i++)
            cout << ans[i].first << ": " << ans[i].second << endl;
    }
}

