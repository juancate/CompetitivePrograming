#include <bits/stdc++.h>

using namespace std;

const int N = 20010;

int n, a[N];

int lis() {
  int j = -1, t;
  vector<int> pre(n,-1), res;
  map<int,int> m;
  map<int,int>::iterator k, l;
  for (int i = 0; i < n; i++) {
    if(m.insert(make_pair(a[i], i)).second) {
      k = m.find(a[i]);
      l = k;
      k++;
      if(l == m.begin())
        pre[i]=-1;
      else {
        l--;
        pre[i]=l->second;
      }
      if(k != m.end())
        m.erase(k);
    }
  }

  k = m.end();
  k--;
  j = k->second;
  while (j != -1) {
    res.push_back(a[j]);
    j = pre[j];
  }

  return res.size();
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n) {
    for (int i = 0; i < n; i++)
      cin >> a[i];

    int x = lis();

    for (int i = 0; i < n; i++)
      a[i] = -a[i];

    int y = lis();

    if (x != y) cout << "Don't worry. I must intervene.\n";
    else cout << "Caution. I will not intervene.\n";
  }

  return 0;
}
