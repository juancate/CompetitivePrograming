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

#define INF 1<<30
#define EPS 1e-13

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> fact[n+1];
  vector<int> tree(n+1, -1);
  vector<bool> on(n+1, false);
  
  for(int i = 2; i <= n; i++) { // sieve
    for(int j = i; j <= n; j += i) {
      fact[j].push_back(i);
    }
  }

  REP(j,m) {
    string ord; int i;
    cin >> ord >> i;

    if(ord == "+") {    
      if(on[i]) {
        cout << "Already on" << endl;
      } else {
        bool conflict = false;
        FOREACH(el, fact[i])  if(tree[*el] != -1) {
          conflict = true;
          cout << "Conflict with " << tree[*el] << endl;
          break;
        }
        if(!conflict) {
          cout << "Success" << endl;
          on[i] = true;
          FOREACH(el, fact[i]) tree[*el] = i;
        }
      }
    } else {
      if(!on[i]) cout << "Already off" << endl;
      else { 
        cout << "Success" << endl;
        on[i] = false;
        FOREACH(el, fact[i]) tree[*el] = -1;
      }
    }
  }
}

