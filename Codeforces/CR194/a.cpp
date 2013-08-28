#include <bits/stdc++.h>

using namespace std;

const int maxn = 111;

int n, total, nn;
vector<int> candies[maxn];
bool seen[maxn*maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  nn = n * n;
  total = nn * (nn+1) / 2 / n;

  int r = nn, l = 1;
  vector< pair<int,int> > p;
  while (l < r) {
    p.push_back(make_pair(l,r));
    l++, r--;
  }

  int pos = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    while (pos < p.size()) {
      sum += p[pos].first + p[pos].second;
      candies[i].push_back(p[pos].first);
      candies[i].push_back(p[pos].second);
      pos++;
      if (sum == total)
        break;
    }
  }

  for (int i = 0; i < n; i++) {
    //sort(candies[i].begin(), candies[i].end());
    int sum = 0;
    for (int j = 0; j < candies[i].size(); j++) {
      cout << candies[i][j] << ' ';
      sum += candies[i][j];
    }
    cout << '\n';
  }

  return 0;
}
