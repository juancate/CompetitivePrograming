#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

int main() {
  int vp, vd, t, f, c;
  cin >> vp >> vd >> t >> f >> c;

  double posp = t*vp;
  int bijus = 0, timer = 0;

  if(vp >= vd) cout << bijus << endl;
  else {
    // first event, dragon parts
    while(posp < c) {
      double time = posp / (vd - vp);
      posp += time*vp;
      if(posp >= c) break;
      else bijus++;
      time = (posp / vd) + f;
      posp += time*vp;
    }
    cout << bijus << endl;
   }
}
