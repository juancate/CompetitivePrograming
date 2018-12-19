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

struct state {
  int chests;
  vector<int> keys;
};

struct chest {
  int key;
  vector<int> keys;
} ch[22];

int n, k;
vector<int> keys, sol;
bool seen[1<<21];

int bfs() {
  memset(seen, 0, sizeof seen);
  queue<state> q;

  state next_state;
  for(int i = 0; i < k; i++) {
    if(keys[i] > 0) {
      next_state.chests = (1 << i);
      next_state.keys = keys;
      next_state.keys[i]--;
      q.push(next_state);
      seen[next_state.chests] = true;
    }
  }

  while(!q.empty()) {
    state curr = q.front();
    q.pop();

    if(curr.chests == (1<<n)-1) {
      for(int i = 0; i < n; i++) {
        if(curr.chests & (1 << i))
          sol.push_back(i);
      }
      return 1;
    }

    for(int i = 0; i < (1<<n); i++) {
      for(int j = 0; j < n; j++) {
        if(!((curr.chests >> j) & 1)) {
          chest c = ch[j];
          if(curr.keys[c.key] > 0) {
            int next = curr.chests | (1<<j);
            if(seen[next]) continue; // !!!!!!
            vector<int> next_keys = curr.keys;
            next_keys[j]--;
            for(int l = 0; l < k; l++)
              next_keys[c.keys[l]]++;
            next_state.chests = next;
            next_state.keys = next_keys;
            q.push(next_state);
          }
        }
      }
    }
  }

  return -1;
}

int main() {
  int t;
  scanf("%d", &t);

  for(int case_id = 1; case_id <= t; case_id++) {
    scanf("%d%d", &k, &n);
    keys.assign(k, 0);

    for(int i = 0; i < k; i++) {
      int key;
      scanf("%d", &key);
      if(key > n) continue;
      keys[key-1]++;
    }

    for(int i = 0; i < n; i++) {
      int key, m;
      scanf("%d%d", &key, &m);
      ch[i].key = key-1;
      ch[i].keys.assign(k, 0);

      for(int j = 0; j < m; j++) {
        int ki;
        scanf("%d", &ki);
        ch[i].keys[ki-1]++;
      }
    }

    int ans = bfs();

    printf("Case #%d:", case_id);
    if(ans < 0)
      printf(" IMPOSSIBLE");
    else
      for(int i = 0; i < sol.size(); i++)
        printf(" %d", sol[i]+1);
    printf("\n");
  }

  return 0;
}

