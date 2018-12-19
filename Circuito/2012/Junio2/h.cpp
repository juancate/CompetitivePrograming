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
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>

#define D(x) cerr << #x " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;
const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int main(int argc, char *argv[]) {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	while(true) {
		map<string, string> male, female, ans;
		string name, gender, seq, genes;
		if(!(cin >> genes)) break;

		int n = genes.size();

		while(true) {
			cin >> name;
			if(name == "***") break;
			cin >> gender >> seq;
			if(gender == "M") male[name] = seq;
			else female[name] = seq;
		}

		FOREACH(f, female) {
			FOREACH(m, male) {
				string mix = f->first + "-" + m->first;
				stringstream ss;

				REP(i, 0, n) {
					if(genes[i] == 'R') {
						if(f->second[i] == '1' && m->second[i] == '1')
							ss << '1';
						else
							ss << '0';
					} else {
						if(f->second[i] == '1' || m->second[i] == '1')
							ss << '1';
						else
							ss << '0';
					}
				}

				ans[mix] = ss.str();
			}
		}

		while(true) {
			string child, seq;
			cin >> child;
			if(child == "***") break;
			cin >> seq;
			bool first = false;
			cout << child << " by ";
			FOREACH(it, ans) {
				if(it->second == seq) {
					if(first) cout << " or ";
					cout << it->first;
					first = true;
				}
			}
			cout << endl;
		}
	}

    return 0;
}
