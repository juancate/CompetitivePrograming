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

const int maxn = 20010;

struct SuffixArray {

    char T[maxn];
    int n;
    int RA[maxn], tempRA[maxn];
    int SA[maxn], tempSA[maxn];
    int LCP[maxn], PLCP[maxn], Phi[maxn];
    int c[maxn];

    SuffixArray() {
        n = 0;
        memset(T, 0, sizeof(T));
    }

    SuffixArray(string str) {
        n = (int)str.size();
        memset(T, 0, sizeof(T));
        for(int i = 0; i < n; i++)
            T[i] = str[i];
    }

    void countingSort(int k) {
        int maxi = max(300, n);

        memset(c, 0, sizeof(c));

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
        T[n++] = '$';

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

    void computeLCP() {
        Phi[SA[0]] = -1;

        for(int i = 1; i < n; i++) {
            Phi[SA[i]] = SA[i-1];
        }

        for(int i = 0, L = 0; i < n; i++) {
            if(Phi[i] == -1) {
                PLCP[i] = 0;
                continue;
            }

            while(T[i + L] == T[Phi[i] + L] && T[i + L] != '$')
                L++;

            PLCP[i] = L;
            L = max(L-1, 0);
        }

        for(int i = 1; i < n; i++) {
            LCP[i] = PLCP[SA[i]];
        }
        LCP[n] = 0;
    }
};
// END Suffix Array

char line[10010];

int main() {
    int t; sscanf(gets(line), "%d", &t);

    while(t--) {
        SuffixArray sa;
        gets(line);

        int m = (int)strlen(line);

        strcat(sa.T, line);
        strcat(sa.T, line);

        sa.n = m+m;

        sa.constructSA();
        /*
        for(int i = 0; i < sa.n; i++)
            cerr << (sa.T + sa.SA[i]) << endl;
        */
        int ans = -1;

        for(int i = 0; i < sa.n; i++) {
            int current = sa.n - 1 - sa.SA[i];
            if(current >= m) {
                //D(sa.T + sa.SA[i]);
                if(sa.SA[i] >= m)
                    ans = sa.SA[i] - m + 1;
                else
                    ans = sa.SA[i] + 1;
                break;
            }
        }
        assert(ans > 0);
        printf("%d\n", ans);
    }
}

