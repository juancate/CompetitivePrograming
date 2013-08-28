#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
	int t, k;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		scanf("%d", &k);
		int j = 1;
		double tax = 0.0;
		int res = k;
		
		while(res > 0) {
			if(j == 1) { // free
				res = res - 180000;
			} else if(j == 2) { // 300k - 10%
				if(res < 300000) {
					tax += (res/10.0);
				}
				else tax += 30000.0;
				res = res - 300000;
			} else if(j == 3) { // 400k - 15%
				if(res < 400000) { 
					tax += ((res*15.0)/100.0);
				}
				else tax += 60000.0;
				res = res - 400000;	
			} else if(j == 4) { // 300k - 20%
				if(res < 300000) {
					tax += (res/5.0);
				}
				else tax += 60000.0;
				res = res - 300000;
			} else { // rest - 25%
				tax += (res/4.0);
				res -= res;
			}
			j++;
		}
		int ans = (int)ceil(tax);
		if(ans > 0 && ans < 2000) ans = 2000;
		printf("Case %d: %d\n", i, ans);
	}
}
