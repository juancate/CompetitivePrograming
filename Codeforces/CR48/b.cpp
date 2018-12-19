#include <bits/stdc++.h>

using namespace std;

const string INVALID = "<>";

string process(string s) {
  int n = s.size();
  string t;

  for (int i = 0; i < n; i++)
    if (INVALID.find(s[i]) == string::npos)
      t.push_back(s[i]);
    else
      t.push_back(' ');

  return t;
}

int table_count;
vector<int> ans;
stringstream expr;
stack<string> stk;

void solve(bool f);

void process_cell() {
  string s;
  while (expr >> s) {
    if (s == "/"+stk.top()) {
      stk.pop();
      break;
    }
    stk.push(s);
    solve(false);
  }
}

int process_row() {
  string s;
  int curr = 0;

  while (expr >> s) {
    if (s == "/"+stk.top()) {
      stk.pop();
      break;
    }
    if (s == "td") {
      stk.push(s);
      curr++;
      process_cell();
    }
  }

  return curr;
}

int process_table() {
  string s;
  int curr = 0;
  while (expr >> s) {
    if (s == "/"+stk.top()) {
      stk.pop();
      break;
    }
    if (s == "tr") {
      stk.push(s);
      curr += process_row();
    }
  }
  return curr;
}

void solve(bool f) {
  string s;

  if (f) {
    expr >> s;
    stk.push(s);
  }

  ans.push_back(process_table());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  stringstream ss;
  string s;
  while (getline(cin, s))
    ss << s;
  s = process(ss.str());
  expr << s;

  table_count = 0;

  solve(true);

  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    if (i) cout << ' ';
    cout << ans[i];
  }
  cout << '\n';

  return 0;
}
