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

#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);

    string line;
    while(getline(cin, line)) {
        stringstream ss(line);

        vector<int> matr;
        int x;

        while(ss >> x) {
            matr.push_back(x);
        }

        stack< pair<int, int> > S;
        bool ok = true;

        int n = (int)matr.size();

        if(n > 0)
            S.push( mp(matr[0], 0) );

        int i;

        for(i = 1; i < n; i++) {
            if(!S.empty() && matr[i] == -S.top().first && matr[i] > 0) {
                int acc = S.top().second;
                S.pop();

                if(acc >= abs(matr[i])) {
                    ok = false;
                    break;
                }

                if(S.empty()) continue;

                int& current = S.top().second;
                current += abs(matr[i]);
            }
            else {
                S.push( mp(matr[i], 0) );
            }
        }

        if(!S.empty() || i < n-1)
            ok = false;

        if(ok) {
            cout << ":-) Matrioshka!\n";
        } else {
            cout << ":-( Try again.\n";
        }
    }
}

