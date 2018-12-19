#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

const int M = 664589;

bitset<10000010> bs;
vector<int> pr;
long long sieve_size;

void sieve(long long up) {
  sieve_size = up+1;
  bs.set();

  bs[0] = bs[1] = 0;

  for (long long i = 2; i <= sieve_size; i++) {
    if (bs[i]) {
      for (long long j = i*i; j <= sieve_size; j += i)
        bs[j] = 0;
      pr.push_back(i);
    }
  }
}

int n;
unordered_map<int, int> nums;
map<int, long long> primes;

void f(int q, int c) {
  for (int p : pr) {
    if ((long long)p * p > q) break;
    if (q % p == 0) {
      primes[p] += c;
      while (q % p == 0)
        q /= p;
    }
  }

  if (q > 1) {
    primes[q] += c;
  }
}

int b[M];
long long sum[M];

void calc() {
  for (pair<int,int> x : nums)
    f(x.first, x.second);

  int tot = 1;
  for (auto it = primes.begin(); it != primes.end(); it++) {
    b[tot] = it->first;
    sum[tot] = sum[tot-1] + it->second;
    tot++;
  }

  int queries;
  cin >> queries;

  while (queries--) {
    int l, r;
    cin >> l >> r;

    int i = lower_bound(b, b+tot, l) - b;
    int j = lower_bound(b, b+tot, r) - b;

    if (j >= tot || b[j] != r)
      j--;

    if (i == j && !primes.count(b[i])) {
      cout << 0 << '\n';
    }
    else {
      cout << sum[j] - sum[i-1] << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve(10000000);

  cin >> n;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    nums[x]++;
  }

  calc();

  return 0;
}
