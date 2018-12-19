#include <bits/stdc++.h>

using namespace std;

const int maxn = 600100;

char T[maxn];
int n;
int RA[maxn], tempRA[maxn];
int SA[maxn], tempSA[maxn];
int LCP[maxn], PLCP[maxn], Phi[maxn];
int c[maxn];

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

  memcpy(SA, tempSA, n * sizeof(int));
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

    memcpy(RA, tempRA, n * sizeof(int));
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

struct item {
  long long s;
  int v;
  item(long long s = 0, int v = 0) :
    s(s), v(v) { }
};

int F;
int len[maxn], id[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> F) {
    if (F == 0)
      break;

    string s;
    stringstream ss;
    int k = 0;
    for (int i = 0; i < F; i++) {
      cin >> s;
      ss << s << '$';

      for (int j = 0; j <= s.size(); j++) {
        len[k] = s.size() - j;
        id[k] = i;
        k++;
      }
    }

    s = ss.str();
    int n = s.size();
    init(s);
    constructSA();
    computeLCP();

    //for (int i = 2; i < s.size(); i++) {
      //cout << SA[i] << '\t' << LCP[i] << '\t'
        //<< s.substr(SA[i-1]) << "\t" << s.substr(SA[i]) << '\n';
    //}

    set<long long> R;
    stack<item> st;

    for (int i = F; i < n; i++) {
      if (LCP[i] < len[SA[i]] && (i+1 == n || LCP[i+1] < len[SA[i]]))
        R.insert(1LL << id[SA[i]]);
    }

    for (int i = F; i < n; i++) {
      long long lasts = 0;
      while (!st.empty() && (st.top().v > LCP[i] || LCP[i] == 0)) {
        item & x = st.top(); st.pop();

        R.insert(x.s);

        if (!st.empty())
          st.top().s |= x.s;

        lasts = x.s;
      }

      if (LCP[i] != 0) {
        if (st.empty() || st.top().v < LCP[i])
          st.push(item((1LL << id[SA[i]] | 1LL << id[SA[i-1]] | lasts), LCP[i]));
        else if (st.top().v == LCP[i])
          st.top().s |= 1LL << id[SA[i]];
      }
    }

    while (!st.empty()) {
      item & x = st.top(); st.pop();

      R.insert(x.s);

      if (!st.empty())
        st.top().s |= x.s;
    }

    cout << R.size() << '\n';
  }

  return 0;
}
