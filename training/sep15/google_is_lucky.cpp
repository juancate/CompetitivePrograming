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

int main() {
    ios_base::sync_with_stdio(false);

    int t; cin >> t;

    for(int case_id = 1; case_id <= t; case_id++) {
        vector< pair<int, string> > pages(10);

        int max_rank = 0;
        for(int i = 0; i < 10; i++) {
            cin >> pages[i].second >> pages[i].first;
            if(pages[i].first > pages[max_rank].first)
                max_rank = i;
        }

        cout << "Case #" << case_id << ":\n";

        for(int i = 0; i < 10; i++)
            if(pages[i].first == pages[max_rank].first)
                cout << pages[i].second << endl;
    }
}

