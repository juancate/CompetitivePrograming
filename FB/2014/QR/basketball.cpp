#include <bits/stdc++.h>

using namespace std;

const int maxn = 33;

int N, M, P, shot[maxn], h[maxn], a[maxn];
string names[maxn];

int played[maxn];
bool seen[maxn];

bool cmp(int i, int j) {
  if (shot[i] == shot[j])
    return h[i] > h[j];
  return shot[i] > shot[j];
}

void inc() {
  for (int i = 0; i < N; i++) {
    if (seen[i])
      played[i]++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int tc = 1; tc <= t; tc++) {
    cin >> N >> M >> P;

    for (int i = 0; i < N; i++) {
      cin >> names[i] >> shot[i] >> h[i];
      a[i] = i;
    }
    sort(a, a+N, cmp);

    vector<int> one, two;
    for (int i = 0; i < N; i++) {
      if (i & 1) two.push_back(a[i]);
      else one.push_back(a[i]);
    }

    memset(seen, 0, sizeof seen);
    memset(played, 0, sizeof played);

    for (int i = 0; i < P; i++) {
      seen[one[i]] = true;
      seen[two[i]] = true;
    }

    inc();
    M--;
    while (M >= 0) {
      int one_playing = -1, two_playing = -1;
      for (int i = 0; i < one.size(); i++)
        if (seen[one[i]]) {
          if (one_playing == -1 || played[one[i]] >= played[one_playing])
            one_playing = one[i];
        }
      for (int i = 0; i < two.size(); i++)
        if (seen[two[i]]) {
          if (two_playing == -1 || played[two[i]] >= played[two_playing])
            two_playing = two[i];
        }

      int best_one = -1, best_two = -1;
      for (int i = 0; i < one.size(); i++) {
        if (!seen[one[i]]) {
          if (best_one == -1 || played[one[i]] < played[best_one])
            best_one = one[i];
        }
      }

      for (int i = 0; i < two.size(); i++) {
        if (!seen[two[i]]) {
          if (best_two == -1 || played[two[i]] < played[best_two])
            best_two = two[i];
        }
      }

      if (one_playing != -1 && two_playing != -1 && best_one != -1 && best_two != -1) {
        seen[one_playing] = seen[two_playing] = false;
        seen[best_one] = seen[best_two] = true;
      }

      inc();

      M--;
    }

    vector<string> ans;
    for (int i = 0; i < N; i++)
      if (seen[a[i]])
        ans.push_back(names[a[i]]);
    sort(ans.begin(), ans.end());

    cout << "Case #" << tc << ":";
    for (int i = 0; i < ans.size(); i++)
      cout << " " << ans[i];
    cout << '\n';
  }

  return 0;
}
