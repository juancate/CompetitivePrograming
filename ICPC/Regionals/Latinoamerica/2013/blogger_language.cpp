#include <bits/stdc++.h>

#define LSOne(x) ((x) & -(x))

using namespace std;

// TLE!

const int maxn = 100010;

int N, n, z[maxn], l[maxn], r[maxn];
string S, T, s;

string tolower(const string & s) {
  string t;
  for (int i = 0; i < s.size(); i++)
    t.push_back(tolower(s[i]));
  return t;
}

void calculate_z() {
  int L = 0, R = 0;
  for (int i = 1; i < n; i++) {
    if (i > R) {
      L = R = i;
      while (R < n && s[R-L] == s[R]) R++;
      z[i] = R-L;
      R--;
    }
    else {
      int k = i-L;
      if (z[k] < R-i+1)
        z[i] = z[k];
      else {
        L = i;
        while (R < n && s[R-L] == s[R]) R++;
        z[i] = R-L;
        R--;
      }
    }
  }
}

class BIT {
public:
  long long dataMul[maxn], dataAdd[maxn];
  int n;

  BIT() {}

  void init(int m) {
    n = ++m;
    fill(dataMul, dataMul+n, 0);
    fill(dataAdd, dataAdd+n, 0);
  }

  void internalUpdate(int at, long long mul, long long add) {
    for (; at <= n; at += LSOne(at)) {
      dataMul[at] += mul;
      dataAdd[at] += add;
    }
  }

  void update(int left, int right, long long by) {
    internalUpdate(left, by, -by * (left - 1));
    internalUpdate(right + 1, -by, by * right);
  }

  long long query(int at) {
    long long mul = 0, add = 0;
    int start = at;

    for (; at > 0; at -= LSOne(at)) {
      mul += dataMul[at];
      add += dataAdd[at];
    }

    return mul * start + add;
  }

  long long query(int a, int b) {
    return query(b) - (a <= 1? 0 : query(a-1));
  }
};

BIT tree;

int miss_matches(int i) {
  int m = S.size();
  int r = 0;

  for (int x = i, j = 0; j < m; x++, j++) {
    int c = tree.query(x, x) & 1;
    int d = isupper(S[j])? 1 : 0;
    if (d != c)
      r++;
  }
  return r;
}

void solve() {
  s = tolower(S) + '$' + tolower(T);
  n = s.size();
  calculate_z();

  int m = T.size();
  int len = S.size();

  vector<int> z_pos;
  for (int i = len+1; i < n; i++) {
    if (z[i] == len)
      z_pos.push_back(i-len);
  }

  tree.init(m);

  for (int i = 1; i <= m; i++)
    tree.update(i, i, isupper(T[i-1])? 1 : 0);

  for (int i = 0; i < N; i++) {
    int ans = -1;

    int j = lower_bound(z_pos.begin(), z_pos.end(), l[i]) - z_pos.begin();
    int k = upper_bound(z_pos.begin(), z_pos.end(), r[i]) - z_pos.begin();

    while (j < k) {
      if (z_pos[j]+len-1 <= r[i])
        ans = max(ans, miss_matches(z_pos[j]));
      j++;
    }
    tree.update(l[i], r[i], 1);
    cout << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> N >> S) {
    cin >> T;

    for (int i = 0; i < N; i++)
      cin >> l[i] >> r[i];

    solve();
  }

  return 0;
}
