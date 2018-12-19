#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

#define D(x) cerr << #x " = " << x << endl;

const double EPS = 1e-13;

using namespace std;


int main() 
{
	
	int a, b;
	int cnt = 1;
	while(~scanf("%d%d", &a, &b) && (a|b) != 0) 
	{
		int ans = 0;
		if(a < 4 && 4 < b) ans++;
		if(a < 16 && 16 < b) ans++;
		if(a < 121 && 121 < b) ans++;
		if(a < 529 && 529 < b) ans++;
		if(a < 4096 && 4096 < b) ans++;
		if(a < 17956 && 17956 < b) ans++;
		if(a < 139129 && 139129 < b) ans++;
		if(a < 609961 && 609961 < b) ans++;
		if(a < 4726276 && 4726276 < b) ans++;
		if(a < 20720704 && 20720704 < b) ans++;
		if(a < 160554241 && 160554241 < b) ans++;
		if(a < 703893961 && 703893961 < b) ans++;
		
		printf("Case %d: %d\n", cnt++, ans);
	}
}
