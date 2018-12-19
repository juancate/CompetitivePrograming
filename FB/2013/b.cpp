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

int m, l;
vector<string> k1, k2;
vector<bool> used;

vector<string> split(const string& s) {
    vector<string> vs;

    for(int i = 0; i < (int)s.size(); i += l) {
        vs.push_back(s.substr(i, l));
    }

    return vs;
}

string solve() {
    vector<int> best(m, -1);
    vector<int> ids(m, -1);
    sort(ALL(k2));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(used[j]) continue;

            if(k1[j] == k2[i]) {
                best[i] = l;
                ids[i] = j;
                used[j] = true;
                break;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        if(ids[i] != -1) continue;
        int curr = -1;
        for(int j = 0; j < m; j++) {
            if(used[j]) continue;
            int cnt = 0;
            for(int k = 0; k < l; k++) {
                if(k1[j][k] == '?' || k2[i][k] == '?')
                    continue;
                if(k1[j][k] == k2[i][k]) {
                    cnt++;
                }
                else {
                    cnt = -1;
                    break;
                }
            }
            if(cnt > best[i]) {
                best[i] = cnt;
                curr = j;
            }
        }
        if(curr == -1) return "IMPOSSIBLE";
        ids[i] = curr;
        used[curr] = true;
    }

    vector< pair<int, string> > sol;
    for(int i = 0; i < m; i++) sol.push_back( make_pair(ids[i], k2[i]) );
    sort(ALL(sol));

    string ret = "";

    for(int i = 0; i < m; i++) {
        string s;
        for(int j = 0; j < l; j++) {
            if(k1[i][j] != '?') s.push_back(k1[i][j]);
            else if(sol[i].second[j] != '?') s.push_back(sol[i].second[j]);
            else s.push_back('?');
        }

        for(int j = 0; j < l; j++)
            if(s[j] == '?') s[j] = 'a';
        ret += s;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    for(int case_id = 1; case_id <= t; case_id++) {
        string s, r;
        cin >> m >> s >> r;
        l = (int)s.size() / m;

        k1 = split(s);
        k2 = split(r);
        used.assign(m, false);

        printf("Case #%d: %s\n", case_id, solve().c_str());
    }

    return 0;
}

