#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);
const int N = 1000010;

long long sieve_size;
bitset<N> bs;
int primes[N], primes_sz;

void sieve(long long up) {
  sieve_size = up+1;

  bs.set();
  bs[0] = bs[1] = false;
  primes_sz = 0;

  for (long long i = 2; i <= sieve_size; i++) if (bs[i]) {
    for (long long j = i*i; j <= sieve_size; j += i)
      bs[j] = false;
    primes[primes_sz++] = i;
  }
}

long long divisors[N];

void fact(int q) {
  int x = q;
  long long tot = 1;

  for (int i = 0; primes[i] * primes[i] <= q; i++) {
    if (q % primes[i] == 0) {
      long long cnt = 0;
      while (q % primes[i] == 0) {
        cnt++;
        q /= primes[i];
      }
      tot = (tot * (cnt + 1));
    }
  }

  if (q > 1) {
    tot = (tot * 2);
  }

  divisors[x] = tot;
}

struct Node {
  int prio, val;
  Node(int p=0, int v=0) : prio(p), val(v) { }

  bool operator<(const Node & o) const {
    if (prio == o.prio)
      return val < o.val;
    return prio > o.prio;
  }
} t[N << 2];

void build(int v, int tl, int tr) {
  if (tl == tr)
    t[v] = Node(divisors[tl], tl);
  else {
    int tm = (tl + tr) >> 1;
    int next = v << 1;
    build(next, tl, tm);
    build(next+1, tm+1, tr);

    t[v] = min(t[next], t[next+1]);
  }
}

Node query(int v, int tl, int tr, int l, int r) {
  if(l > tr || r < tl)
    return Node(-INF, INF);

  if(l <= tl && tr <= r)
    return t[v];

  int tm = (tl + tr) >> 1;
  int next = v << 1;

  Node left_part = query(next, tl, tm, l, r);
  Node right_part = query(next+1, tm+1, tr, l, r);

  return min(left_part, right_part);
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve(1000000);

  divisors[1] = 1;
  int limit = 1000000;
  for (int i = 2; i <= limit; i++)
    fact(i);

  build(1, 1, limit);

  int tc;
  cin >> tc;

  while (tc--) {
    long long n;
    cin >> n;

    Node ans = query(1, 1, limit, 1, min(n, (long long)limit));
    cout << ans.val << '\n';
  }

  return 0;
}
