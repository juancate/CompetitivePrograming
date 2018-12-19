#include <bits/stdc++.h>

#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

const int maxt = 110;
const int maxn = 5010;

int capitans[maxt], sizes[maxn];
string teams[maxt];

vector<int> friends[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, n, case_id = 1;
  while(cin >> t >> n && (t|n)) {
    for (int i = 0; i < t; i++) {
      string team_name; cin >> team_name;
      teams[i] = team_name;

      int capitan; cin >> capitan;
      capitans[i] = capitan;
    }

    int team_size = n / t;

    for (int i = 0; i < n; i++) {
      int p, s, k;
      cin >> p >> s >> k;

      sizes[p] = s;
      vector<int> fr;
      for (int j = 0; j < k; j++) {
        int v; cin >> v;
        fr.push_back(v);
      }
      fr.push_back(p);
      sort(ALL(fr));
      friends[p] = fr;
    }

    for (int i = 0; i < t; i++) {
      int capitan = capitans[i];
      vector<int> fr = friends[capitan];

      foreach (p, fr) {
        if (*p == capitan) continue;

        vector<int> inter(friends[*p].size() + friends[capitan].size());
        vector<int>::iterator it;

        it = set_intersection(ALL(friends[*p]), ALL(friends[capitan]),
            inter.begin());
        inter.resize(it - inter.begin());

        if (inter.size() == team_size)
          friends[capitan] = inter;
      }
    }

    cout << "Case " << case_id++ << ":" << '\n';
    for (int i = 0; i < t; i++) {
      cout << teams[i] << '\n';

      int capitan = capitans[i];
      map<int, int> cnt;

      foreach (p, friends[capitan])
        cnt[sizes[*p]]++;

      foreach (s, cnt)
        cout << s->first << " " << s->second << '\n';
    }
  }

  return 0;
}

