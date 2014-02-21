#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s) {
  vector<string> vs;
  int n = s.size();

  for (int i = 0; i < n; i++) {
    string t;
    while (i < n && s[i] == '|')
      t.push_back(s[i++]);
    vs.push_back(t);
  }
  return vs;
}

int to_i(string s) {
  return s.size();
}

void print(int x) {
  while (x--)
    cout << '|';
}

void solve(vector<int> nums) {
  int a = nums[0], b = nums[1], c = nums[2];

  bool changed = false;
  if (a + b != c) {
    if (a < b) {
      swap(a, b);
      changed = true;
    }

    if (a + b < c) {
      a++;
      c--;
    }
    else if (a + b > c) {
      a--;
      c++;
    }
  }

  if (a + b != c) {
    cout << "Impossible\n";
    return;
  }

  if (changed)
    swap(a, b);

  print(a); cout << '+'; print(b); cout << '='; print(c); cout << '\n';
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  vector<string> vs = split(s);
  vector<int> nums;
  for (int i = 0; i < vs.size(); i++)
    nums.push_back(to_i(vs[i]));

  solve(nums);

  return 0;
}
