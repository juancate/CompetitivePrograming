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

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;


int main() {
    int n;
    scanf("%d", &n);

    priority_queue<int> heap1;
    priority_queue< int, vector<int>, greater<int> > heap2;
    int size = 0;

    while(n--) {
        int f, x;
        scanf("%d", &f);

        if(f == 1) {
            scanf("%d", &x);

            size++;

            if(size % 3 == 0) {
                heap1.push(x);
                int y = heap1.top();
                heap1.pop();

                heap2.push(y);
            } else {
                heap2.push(x);
                int y = heap2.top();
                heap2.pop();

                heap1.push(y);
            }
        } else {
            if(size / 3 == 0) {
                puts("No reviews yet");
            } else {
                printf("%d\n", heap2.top());
            }
        }
    }
}

