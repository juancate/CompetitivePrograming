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

typedef pair<int,int> ii;

int main() {
  int n;
  cin >> n;
  vector<ii> players(n);
  REP(i, n) {
    int x;
    cin >> x;
    players[i] = ii(x, i+1);
  }
  sort(players.begin(), players.end());

  vector<int> team1, team2;
  int maxskill = players[n-1].first, sumteam1 = 0, sumteam2 = 0;

  REP(i, n) {
    ii p = players[i];
    int skill = p.first;

    if(abs(team1.size() + 1 - team2.size()) <= 1)  {
      if(abs(sumteam1 + skill - sumteam2) <= maxskill) {
        if(team1.size() + 1 + team2.size() == (i + 1)) {
          team1.push_back(p.second);
          sumteam1 += skill;
        }
      } else {
        if(abs(sumteam2 + skill - sumteam1) <= maxskill)
          if(team2.size() + 1 + team1.size() == (i + 1)) {
            team2.push_back(p.second);
            sumteam2 += skill;
          }
      }
    }
    else {
      if(abs(sumteam2 + skill - sumteam1) <= maxskill)
        if(team2.size() + 1 + team1.size() == (i + 1)) {
          team2.push_back(p.second);
          sumteam2 += skill;
        }
    }
  }

  cout << team1.size() << endl;
  REP(i, team1.size()) {
    if(i) cout << " ";
    cout << team1[i];
  }
  cout << endl << team2.size() << endl;
  REP(i, team2.size()) {
    if(i) cout << " ";
    cout << team2[i];
  }
  cout << endl;
}

