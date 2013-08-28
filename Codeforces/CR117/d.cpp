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
    string A, B;
    cin >> A >> B;
    
    int len = min(A.length(), B.length());
    int maxlen = max(A.length(), B.length());
    int cnt = 0;

    vector<bool> valids(len + 1, false);

    valids[0] = true;
  
    REP(i, 0, len) {
        if(valids[i] and A[i] == B[i]) {
            if(maxlen % (i + 1) == 0) {
                bool a = true, b = true;
                for(int k = (i + 1); k < maxlen; k += (i + 1)) {
                    for(int r = 0, s = k; r < (i + 1); r++, s++) {
                        if(s < A.length()) {              
                            if(A[r] != A[s]) {
                                a = false;
                                break;
                            }
                        } else if(A.length() % (i + 1)) {
                            a = false;
                            break;
                        }       
                        
                        if(s < B.length()) {
                            if(A[r] != B[s]) {
                                b = false;
                                break;
                            }
                        } else if(B.length() % (i + 1)) {
                            b = false;
                            break;
                        }
                    }
                    if(!a and !b) break;
                }
                if(a and b) {
                    cnt++;
                }
            }
            valids[i + 1] = valids[i];
        }
        
        if(!valids[i]) break;
    }

    cout << cnt << endl;
}

