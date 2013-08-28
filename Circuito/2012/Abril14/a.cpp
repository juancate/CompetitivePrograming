#include <algorithm>
#include <complex>
#include <list>
#include <stack>
#include <bitset>
#include <locale>
#include <stdexcept>
#include <cassert>
#include <map>
#include <cctype>
#include <string>
#include <cfloat>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <utility>
#include <climits>
#include <cstring>
#include <istream>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <deque>
#include <limits>
#include <sstream>
#include <iomanip>

#define D(x) cerr << #x " = " << (x) << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	long long A, B;
	int cases = 1;

	while(cin >> A >> B and (A|B) != 0) {
		long long n = B;
		long long answer = 0, mov = 1;
		vector<long long> result;
		while(n > 0) {
			long long prod = A * (n % 10);
			answer += prod * mov;
			result.push_back(prod);
			n /= 10;
			mov *= 10;
		}
		stringstream ss;
		ss << answer;
		int length = ss.str().length();
		
		cout << "Problem " << cases << '\n';
		cases++;
		
		cout << setw(length);
		cout << A << '\n' << setw(length) << B << '\n';
		
		REP(i, 0, length) cout << '-';
		cout << '\n';
		
		char buff[(int)result.size()][length];
		memset(buff, ' ', sizeof(buff));
		
		int zeros = 0, spaces = 0, cnt = 0;
		REP(i, 0, result.size()) {
			if(result[i] == 0) {
				zeros++;
			}
			else {
				int prod = 1;
				REP(j, 0, zeros) prod *= 10;
				long long num = result[i] * prod;
				ss.str("");
				ss << num;
				string s = ss.str();
				int end = length;
				for(int k = length-1, j = s.size() - 1; k >= 0 and j >= 0; k--) {
					if(spaces > 0) {
						spaces--;
						if(spaces == 0) end = k;
					}
					else {
						buff[i][k] = s[j--];
					}
				}
				for(int k = 0; k < end; k++) cout << buff[i][k];
				cout << '\n';
				zeros = 0;
				spaces = i+1;
				cnt++;
			}
		}
		if(cnt > 1) {
			REP(i, 0, length) cout << '-';
			cout << '\n';
			cout << answer << endl;
		}
	}
}
