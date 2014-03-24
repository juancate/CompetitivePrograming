#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);
const int N = 500100;

char T[N];
int n;
int RA[N], tempRA[N];
int SA[N], tempSA[N];
int LCP[N], PLCP[N], Phi[N];
int c[N];

void init(const string & str) {
  n = (int)str.size();
  memset(T, 0, sizeof(T));
  for(int i = 0; i < n; i++)
    T[i] = str[i];
}

void countingSort(int k) {
  int maxi = max(300, n);

  memset(c, 0, sizeof(c));

  for(int i = 0; i < n; i++) {
    if(i + k < n)
      c[RA[i+k]]++;
    else
      c[0]++;
  }

  for(int i = 0, sum = 0; i < maxi; i++) {
    int t = c[i];
    c[i] = sum;
    sum += t;
  }

  for(int i = 0; i < n; i++) {
    if(SA[i] + k < n) {
      tempSA[ c[RA[SA[i] + k]] ] = SA[i];
      c[RA[SA[i] + k]]++;
    }
    else {
      tempSA[c[0]] = SA[i];
      c[0]++;
    }
  }

  for (int i = 0; i < n; i++)
    SA[i] = tempSA[i];
}

void constructSA() {
  for(int i = 0; i < n; i++)
    RA[i] = T[i] - '$';

  for(int i = 0; i < n; i++)
    SA[i] = i;

  int rank;

  for(int k = 1; k < n; k <<= 1) {
    countingSort(k);
    countingSort(0);

    tempRA[SA[0]] = rank = 0;

    for(int i = 1; i < n; i++) {
      if(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1] + k]) {
        tempRA[SA[i]] = rank;
      }
      else {
        rank++;
        tempRA[SA[i]] = rank;
      }
    }

    for (int i = 0; i < n; i++)
      RA[i] = tempRA[i];
  }
}

void computeLCP() {
  Phi[SA[0]] = -1;

  for(int i = 1; i < n; i++) {
    Phi[SA[i]] = SA[i-1];
  }

  for(int i = 0, L = 0; i < n; i++) {
    if(Phi[i] == -1) {
      PLCP[i] = 0;
      continue;
    }

    while(T[i + L] != '$' && T[i + L] == T[Phi[i] + L])
      L++;

    PLCP[i] = L;
    L = max(L-1, 0);
  }

  for(int i = 1; i < n; i++) {
    LCP[i] = PLCP[SA[i]];
  }
  LCP[n] = 0;
}
// END Suffix Array

const int S = 2;
int len[S], owner[N];

int z[N];

void calculate_z(const string & s) {
  int L = 0, R = 0, n = s.size();
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
int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s1, s2;
  cin >> s1 >> s2;

  len[0] = s2.size();
  len[1] = s1.size();

  string s = s2 + "$" + s1 + "$";

  init(s);
  constructSA();
  computeLCP();

  for (int i = 0; i < n; i++) {
    if (SA[i] < len[0])
      owner[i] = 0;
    else
      owner[i] = 1;
  }

  int best = 0, idx = INF;

  vector<int> sa;
  for (int i = 2; i < n; i++) {
    if (owner[i] != owner[i-1]) {
      if (LCP[i] == 0)
        continue;

      if (LCP[i] == best)
        sa.push_back(SA[i]);
      else if (LCP[i] > best) {
        sa.clear();
        sa.push_back(SA[i]);
        best = LCP[i];
      }
    }
  }

  for (int i : sa) {
    string t = s.substr(i, best) + "$" + s2;
    calculate_z(t);

    for (int i = 0; i < t.size(); i++) {
      if (z[i] == best)
        idx = min(idx, i - best - 1);
    }
  }

  if (best != 0) {
    cout << s.substr(idx, best) << '\n';
  }
  cout << best << '\n';

  return 0;
}
