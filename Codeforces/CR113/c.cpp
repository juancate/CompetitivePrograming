#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
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
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

#define INF 1<<30
#define EPS 1e-13

using namespace std;

#ifdef DEBUG
#include "../../debug.h"
#endif

int main() {
    ios_base::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;

    vector<int> numbers(n);
    REP(i,n) cin >> numbers[i];

    sort(ALL(numbers));

    int ans = 0;

    int low = lower_bound(ALL(numbers), x) - numbers.begin();

    if(numbers[low] != x) {
        numbers.insert(numbers.begin() + low, x);
        ans++;
        n++;
    }

    int mid = (n + 1) / 2;
    mid--;
    while(numbers[mid] != x) {
        if(numbers[mid] < x) {
            numbers.push_back(100000);
        } else {
            numbers.insert(numbers.begin(), 1);
        }
        n = numbers.size();
        mid = (n + 1) / 2;
        mid--;
        ans++;
    }
    cout << ans << endl;
}

