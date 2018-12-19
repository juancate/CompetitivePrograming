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
#include <set>
#include <map>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

bool endsWith(string a, string b) {
  int m = b.size();
  int n = a.size();

  if(n < m) return false;

  string t = a.substr(n-m);
  return t == b;
}

// 0 male 1 female -1 invalid
int gender(string s) {
  if(endsWith(s, "lios") || endsWith(s, "etr") || endsWith(s, "initis"))
    return 0;
  if(endsWith(s, "liala") || endsWith(s, "etra") || endsWith(s, "inites"))
    return 1;
  return -1;
}

// 0 adj 1 noun 2 verb -1 invalid
int type(string s) {
  if(endsWith(s, "lios") || endsWith(s, "liala"))
    return 0;
  if(endsWith(s, "etr") || endsWith(s, "etra"))
    return 1;
  if(endsWith(s, "initis") || endsWith(s, "inites"))
    return 2;
  return -1;
}

bool isStatement(vector<string> sentence) {
  int g = gender(sentence[0]);
  int t = type(sentence[0]);
  int n = sentence.size();
  int i = 0;

  if(t == 0) {
    for(i = 1; i < n; i++) {
      int currg = gender(sentence[i]);
      t = type(sentence[i]);
      if(currg != g) return false;
      if(t != 0)
        break;
    }
  }

  if(t != 1) return false;

  i++;
  if(i < n) {
    int currg = gender(sentence[i]);
    t = type(sentence[i]);
    if(t != 2) return false;
    for(; i < n; i++) {
      currg = gender(sentence[i]);
      t = type(sentence[i]);
      if(currg != g || t != 2)
        return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  vector<string> sentence;
  string s;
  while(cin >> s) sentence.push_back(s);

  if(sentence.size() == 1) {
    if(type(sentence[0]) != -1) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  else {
    if(isStatement(sentence)) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }

  return 0;
}

