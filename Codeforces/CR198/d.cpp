#include <bits/stdc++.h>

using namespace std;

int LIS(const vector<int>& A) {
  int N = A.size(), t;
  vector<int> pre(N,-1), res;
  map<int,int> m;
  map<int,int>::iterator k, l;
  for (int i = 0; i < N; i++) {
    if (m.insert(make_pair(A[i], i)).second) {
      k = m.find(A[i]);
      l = k;
      k++;
      if (l == m.begin())
        pre[i] = -1;
      else {
        l--;
        pre[i] = l->second;
      }
      if (k != m.end())
        m.erase(k);
    }
  }
  k = m.end();
  k--;
  for (int j = k->second; j != -1; j = pre[j])
    res.push_back(A[j]);
  reverse(res.begin(), res.end());
  return res.size();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cout << LIS(a) << '\n';

  return 0;
}

