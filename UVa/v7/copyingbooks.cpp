#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl

// Binary Search

using namespace std;

typedef long long ll;

int N, m, k;
ll total;
vector<ll> p;

bool check(ll val) {
	int j = 1;
	ll sum = 0;

	for(int i = 0; i < m; i++) {
    if(p[i] > val) return false; // necesito un val mas grande
		if(sum + p[i] > val) {
			sum = p[i];
			j++;
		} else {
			sum += p[i];
		}
	}
  return (j <= k); // true: necesito mas libros. false: necesito menos.
}

ll binarySearch(ll low, ll end) {
	ll lo = low, hi = end, mid;
	while(lo < hi) {
		mid = lo + (hi - lo)/2;
    bool ret = check(mid);

		if(ret)
			hi = mid;
		else
			lo = mid+1;
	}
	return lo;
}

int main() {
	scanf("%d", &N);
	while(N--) {
		scanf("%d %d", &m, &k);
		p.resize(m);
		total = 0;
		for(int i = 0; i < m; i++) {
			scanf("%lld", &p[i]);
			total += p[i];
		}

		ll ans = binarySearch(0, total);
    
		ll subsum = 0;

    vector<int> scribbers[k];
    
    for(int i = m-1, j = k-1; i >= 0 and j >= 0; i--) {
      if(subsum + p[i] <= ans and (i >= j)) {
        subsum += p[i];
      }
      else {
        subsum = p[i];
        j--;
      }
      scribbers[j].push_back(p[i]);      
    }
    
    for(int i = 0; i < k; i++) {
      int sz = scribbers[i].size();
      for(int j = sz - 1; j >= 0; j--) {
        if(j < sz - 1) printf(" ");
        printf("%d", scribbers[i][j]);
      }
      if(i < k-1) printf(" / ");
    }
		puts("");
	}
}
