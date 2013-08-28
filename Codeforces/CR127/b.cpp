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

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

bool check(vector<string> a, vector<string> b) {
    int n = a.size(), m = b.size();

    if(m < n) return false;

    int memo[n+2][m+2];

    memset(memo, 0, sizeof(memo));

    REP(i, 0, n) {
        REP(j, 0, m) {
            if(a[i] == b[j])
                memo[i+1][j+1] = memo[i][j] + 1;
            else
                memo[i+1][j+1] = max(memo[i][j+1], memo[i+1][j]);
        }
    }

    return n == memo[n][m];
}

int inversions(const vector<int>& a) {
    int n = a.size();
    int inv = 0;
    REP(i, 0, n) {
        REP(j, i+1, n) {
            if(a[i] > a[j]) inv++;
        }
    }
    return inv;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    vector<string> problem;

    cin >> n;

    vector<int> seq(n);
    REP(i, 0, n) {
        string x;
        cin >> x;
        problem.push_back(x);
        seq[i] = i;
    }

    int m;
    cin >> m;

    int inv = INF;
    int index = -1;

    vector< vector<string> > archives;

    REP(i, 0, m) {
        int k;
        cin >> k;
        vector<string> archive;

        REP(j, 0, k) {
            string x;
            cin >> x;
            archive.push_back(x);
        }

        archives.push_back(archive);
    }

    int best_p = -INF;

    do {
        int v = inversions(seq);

        vector<string> p(n);
        REP(s, 0, n) p[s] = problem[seq[s]];

        REP(i, 0, m) {
            if(check(p, archives[i])) {
                int val = n * (n - 1) / 2 - v + 1;
                if(val > best_p) {
                    index = i;
                    inv = v;
                    best_p = val;
                } else if(val == best_p) {
                    if(i < index) index = i;
                }
            }
        }
    } while(next_permutation(ALL(seq)));


    if(index != -1) {
        cout << (index + 1) << endl;
        cout << "[:";
        REP(i, 0, best_p) cout << '|';
        cout << ":]\n";
    } else {
        cout << "Brand new problem!" << endl;
    }
}

