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

struct node {
  string key;
  node* left, *right;

  node(string k, node* l = NULL, node* r = NULL) {
    key = k;
    left = l;
    right = r;
  }
} *t;

int n, cnt, i;
bool ok;
vector<string> ss;

void split() {
  string s;
  cin.ignore();
  getline(cin, s);
  stringstream iss(s);

  while(iss >> s)
    ss.push_back(s);
}

node* solve() {
  if(cnt == n) {
    return NULL;
  }

  string k = ss[i++];

  node* curr = new node(k);
  if(k == "pair") {
    curr->left = solve();
    curr->right = solve();

    if(curr->left == NULL || curr->right == NULL)
      ok = false;
  }
  else {
    cnt++;
  }
  return curr;
}

void print(node* curr) {
  if(curr == NULL)
    return;
  cout << curr->key;
  if(curr->key == "pair") {
    cout << "<"; print(curr->left); cout << ",";
    print(curr->right); cout << ">";
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  cin >> n;
  split();

  ok = true;
  cnt = 0, i = 0;
  t = solve();

  if(!ok || cnt != n || i != ss.size())
    cout << "Error occurred";
  else
    print(t);
  cout << endl;
}

