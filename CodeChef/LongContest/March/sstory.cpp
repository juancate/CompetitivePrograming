#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);
const int MAX_LEN = 500010;
const int LOG2_LEN = 20;

#define rank _rank
#define next _next
#define ALPH_SIZE 123

char A[MAX_LEN+1];
int N,pos[MAX_LEN],rank[MAX_LEN];
int cont[MAX_LEN],next[MAX_LEN];
bool bh[MAX_LEN+1],b2h[MAX_LEN+1];

void build_suffix_array(){
  N = strlen(A);

  memset(cont,0,sizeof(cont));

  for(int i = 0;i<N;++i) ++cont[A[i]];
  for(int i = 1;i<ALPH_SIZE;++i) cont[i] += cont[i-1];
  for(int i = 0;i<N;++i) pos[--cont[A[i]]] = i;

  for(int i = 0;i<N;++i){
    bh[i] = (i==0 || A[pos[i]]!=A[pos[i-1]]);
    b2h[i] = false;
  }

  for(int H = 1;H<N;H <<= 1){
    int buckets = 0;

    for(int i = 0,j;i<N;i = j){
      j = i+1;

      while(j<N && !bh[j]) ++j;
      next[i] = j;
      ++buckets;
    }

    if(buckets==N) break;

    for(int i = 0;i<N;i = next[i]){
      cont[i] = 0;
      for(int j = i;j<next[i];++j)
        rank[pos[j]] = i;
    }

    ++cont[rank[N-H]];
    b2h[rank[N-H]] = true;

    for(int i = 0;i<N;i = next[i]){
      for(int j = i;j<next[i];++j){
        int s = pos[j]-H;

        if(s>=0){
          int head = rank[s];
          rank[s] = head+cont[head];
          ++cont[head];
          b2h[rank[s]] = true;
        }
      }

      for(int j = i;j<next[i];++j){
        int s = pos[j]-H;

        if(s>=0 && b2h[rank[s]]){
          for(int k = rank[s]+1;!bh[k] && b2h[k];++k)
            b2h[k] = false;
        }
      }
    }

    for(int i = 0;i<N;++i){
      pos[rank[i]] = i;
      bh[i] |= b2h[i];
    }
  }

  for(int i = 0;i<N;++i) rank[pos[i]] = i;
}

int height[MAX_LEN];
// height[i] = lcp(pos[i],pos[i-1])

void get_height(){
  height[0] = 0;

  for(int i = 0,h = 0;i<N;++i){
    if(rank[i]>0){
      int j = pos[rank[i]-1];

      while(i+h<N && j+h<N && A[i+h]==A[j+h]) ++h;
      height[rank[i]] = h;
      if(h>0) --h;
    }
  }
}

int RMQ[MAX_LEN][LOG2_LEN + 1];

void init_rmq(){
  for(int i = 0;i<N;++i) RMQ[i][0] = height[i];

  for(int j = 1;(1<<j)<=N;++j){
    for(int i = 0;i+(1<<j)-1<N;++i){
      if(RMQ[i][j-1]<=RMQ[i+(1<<(j-1))][j-1])
        RMQ[i][j] = RMQ[i][j-1];
      else
        RMQ[i][j] = RMQ[i+(1<<(j-1))][j-1];
    }
  }
}

// lcp(pos[x],pos[y])
int lcp(int x, int y){
  if(x==y) return N-rank[x];
  if(x>y) swap(x,y);

  int log = 0;
  while((1<<log)<=(y-x)) ++log;
  --log;

  return min(RMQ[x+1][log],RMQ[y-(1<<log)+1][log]);
}

// END Suffix Array

int z[MAX_LEN];

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

  string s = s2 + "\1" + s1 + "\2";
  for (int i = 0; i < s.size(); i++)
    A[i] = s[i];

  build_suffix_array();
  get_height();
  init_rmq();

  int best = 0, idx = INF;
  vector<int> sa;
  for (int i = 1; i < s.size(); i++) {
    int LCP = lcp(i, i-1);
    bool left = pos[i-1] + LCP <= s2.size();
    bool right = pos[i] + LCP <= s2.size();

    if (LCP && (left ^ right)) {
      if (LCP == best)
        sa.push_back(pos[i]);
      else if (LCP > best) {
        sa.clear();
        sa.push_back(pos[i]);
        best = LCP;
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

  if (best != 0)
    cout << s.substr(idx, best) << '\n';
  cout << best << '\n';

  return 0;
}
