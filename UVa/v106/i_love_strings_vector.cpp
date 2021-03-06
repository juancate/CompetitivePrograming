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

const int maxn = 100010;

int strncmp(const string& a, int i, const string& b, int j, int n) {
    for(int k = 0; i+k < (int)a.size() && j+k < (int)b.size(); k++) {
        if(a[i+k] != b[j+k]) return a[i+k] - b[j+k];
    }
    return 0;
}

struct SuffixArray {
    int n;
    string T;
    vector<int> RA, tempRA, SA, tempSA, c;
    
    SuffixArray() {
        n = 0;
        RA.resize(maxn);
        tempRA.assign(maxn, 0);
        SA.assign(maxn, 0);
        tempSA.assign(maxn, 0);
        c.assign(maxn, 0);
    }
    
    SuffixArray(const string & str) {
        T = str;
        n = (int)T.size();

        RA.assign(maxn, 0);
        tempRA.assign(maxn, 0);
        SA.assign(maxn, 0);
        tempSA.assign(maxn, 0);
        c.assign(maxn, 0);
    }
    
    void countingSort(int k) {
        int maxi = max(300, n);
        
        fill(c.begin(), c.end(), 0);
        
        for(int i = 0; i < n; i++) {
            if(i + k < n)
                c[RA[i+k]]++;
            else
                c[0]++;
        }
        
        for(int i = 0, sum = 0; i < maxi; i++) {
            int t = c[i];
            c[i] = sum;
            sum += t;
        }
        
        for(int i = 0; i < n; i++) {
            if(SA[i] + k < n) {
                tempSA[ c[RA[SA[i] + k]] ] = SA[i];
                c[RA[SA[i] + k]]++;
            }
            else {
                tempSA[c[0]] = SA[i];
                c[0]++;
            }
        }
        
        for(int i = 0; i < n; i++)
            SA[i] = tempSA[i];
    }
    
    void constructSA() {
        //T[n++] = '$';
        T.push_back('$');
        n++;
        
        for(int i = 0; i < n; i++)
            RA[i] = T[i] - '$';

        for(int i = 0; i < n; i++)
            SA[i] = i;

        int rank;
        
        for(int k = 1; k < n; k <<= 1) {
            countingSort(k);
            countingSort(0);
            
            tempRA[SA[0]] = rank = 0;
            
            for(int i = 1; i < n; i++) {
                if(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1] + k]) {
                    tempRA[SA[i]] = rank;
                }
                else {
                    rank++;
                    tempRA[SA[i]] = rank;
                }
            }
            
            for(int i = 0; i < n; i++)
                RA[i] = tempRA[i];
        }
    }
    
    pair<int, int> stringMatching(const string& P) {
        int lo = 0, hi = n-1, mid = lo;
        int m = (int)P.size();

        while(lo < hi) {
            mid = (lo + hi) / 2;
            int res = strncmp(T, SA[mid], P, 0, m);

            if(res >= 0) hi = mid;
            else lo = mid+1;
        }

        if(strncmp(T, SA[lo], P, 0, m) != 0)
            return make_pair(-1, -1);
            
        pair<int, int> ans;
        ans.first = lo;
        
        lo = 0; hi = n-1; mid = lo;
        
        while(lo < hi) {
            mid = (lo + hi) / 2;
            int res = strncmp(T, SA[mid], P, 0, m);

            if(res > 0) hi = mid;
            else lo = mid+1;
        }
        
        if(strncmp(T, SA[hi], P, 0, m) != 0)
            hi--;
        
        ans.second = hi;
        return ans;
    }
};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
#endif

    int t;
    cin >> t;

    while(t--) {
        string str;
        cin >> str;
        
        //construct SA
        SuffixArray sa(str);
        sa.constructSA();
        
        int Q;
        cin >> Q;
        
        while(Q--) {
            cin >> str;
            //query
            pair<int, int> ans = sa.stringMatching(str);

            if(ans.first != -1 && ans.second != -1)
                cout << 'y' << endl;
            else
                cout << 'n' << endl;
        }
    }
    return 0;
}
