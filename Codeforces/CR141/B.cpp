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

const int maxn = 51;

int a[maxn][maxn], b[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false);
    int na, ma;

    cin >> na >> ma;

    REP(i, 0, na) {
        string s; cin >> s;
        REP(j, 0, ma) {
            a[i][j] = s[j]-'0';
        }
    }

    int nb, mb;
    cin >> nb >> mb;

    REP(i, 0, nb) {
        string s; cin >> s;
        REP(j, 0, mb) {
            b[i][j] = s[j]-'0';
        }
    }


    int xf, yf, ans = -1;
    int rows = max(na, nb), cols = max(ma, mb);

    REP(x, -49, 50) {
        REP(y, -49, 50) {
            int current = 0;
            REP(i, 0, rows) {
                REP(j, 0, cols) {
                    if(i+x < 0 || j+y < 0) continue;
                    if(i >= na || j >= ma || i+x >= nb || j+y >= mb)
                        continue;

                    current += a[i][j] * b[i+x][j+y];
                }
            }
            if(current > ans) {
                ans = current;
                xf = x, yf = y;
            }
        }
    }
    cout << xf << ' ' << yf << endl;
}

