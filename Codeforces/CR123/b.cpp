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

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> ord;
    int mid = (m + 1) / 2;
    ord.push_back(mid);
    double midd = (m + 1) / 2.;
    int left = mid - 1;
    int right = mid + 1;
    //D(midd);
    n--;
    int turn = 0;
    while(n > 0) {
        if(right - midd < midd - left && right < m + 1) {
            turn = 1;
        } else {
            turn = 0;
        }
        //D(left); D(right); D(n);

        if(turn == 0) {
            if(left > 0) {
                ord.push_back(left);
                left--;
                n--;
            }
            //turn = 1;
        } else if(turn == 1) {
            if(right < m + 1) {
                ord.push_back(right);
                right++;
                n--;
            }
            //turn = 0;
        }

        if(left <= 0 && right > m) break;
    }

    int size = ord.size();

    REP(i, 0, size) cout << ord[i] << endl;
    int j = 0;
    while(n > 0) {
        cout << ord[j % size] << endl;
        n--;
        j++;
    }
}

