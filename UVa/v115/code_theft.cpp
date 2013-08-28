#include <bits/stdc++.h>

using namespace std;

typedef vector<long long> CODE;

struct FRAGMENT {
  string name;
  CODE code;
} f[100];

int n;
CODE in;

string trim(string s) {
  vector<char> t;

  int m = s.size();
  int i;
  for (i = 0; i < m && s[i] == ' '; i++);
  for (; i < m; i++) {
    t.push_back(s[i]);
    if (s[i] == ' ')
      while (i+1 < m && s[i+1] == ' ')
        i++;
  }

  m = t.size();
  for (i = m-1; i >= 0; i--) {
    if (t[i] != ' ') break;
    t.pop_back();
  }

  return string(t.begin(), t.end());
}

long long hash(string s) {
  int p = 31;
  long long h = 0, p_pow = 1;
  for (int i = 0; i < s.size(); i++) {
    h += (s[i]-'a'+1) * p_pow;
    p_pow *= p;
  }
  return h;
}

int compare(int k) {
  int m = in.size();
  int l = f[k].code.size();
  int best = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < l; j++) {
      int curr = 0;
      while (j < l && f[k].code[j] != in[i]) j++;
      for (int r = j, s = i; r < l; r++, s++) {
        if (f[k].code[r] != in[s])
          break;
        curr++;
      }
      best = max(best, curr);
    }
  }
  return best;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n) {
    string s;
    for (int i = 0; i < n; i++) {
      cin >> f[i].name;
      f[i].code.clear();
      cin.get();
      while (getline(cin, s)) {
        if (s == "***END***")
          break;
        s = trim(s);
        if (s.size())
          f[i].code.push_back(hash(s));
      }
    }

    in.clear();
    while (getline(cin, s)) {
      if (s == "***END***")
        break;
      s = trim(s);
      if (s.size())
        in.push_back(hash(s));
    }

    int best = 0;
    vector<string> ans;
    for (int i = 0; i < n; i++) {
      int curr = compare(i);
      if (curr > best) {
        best = curr;
        ans.clear();
        ans.push_back(f[i].name);
      }
      else if (curr == best)
        ans.push_back(f[i].name);
    }
    cout << best;
    for (int i = 0; best && i < ans.size(); i++)
      cout << ' ' << ans[i];
    cout << '\n';
  }

  return 0;
}
