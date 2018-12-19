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
#include <set>
#include <map>
#include <algorithm>

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

#ifdef L
#include "../../debug.h"
#endif

typedef vector<string> vs;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    map< string, vector<vs> > procedures;
    cin >> n;
    cin.get();
    REP(i,0,n) {
        string line;
        getline(cin, line);
        REP(j, 0, line.size()) {
            if(line[j] == '(' || line[j] == ')' || line[j] == ',')
                line = line.substr(0, j) + ' ' + line.substr(j+1);
        }
        stringstream ss(line);
        string v, name, param;
        ss >> v >> name;
        procedures[name].push_back(vs());
        int k = procedures[name].size()-1;
        while(ss >> param) {
            procedures[name][k].push_back(param);
        }
    }

    map<string, string> types;
    int m;
    cin >> m;
    cin.get();
    REP(i, 0, m) {
        string type, name;
        cin >> type >> name;
        types[name] = type;
    }

    int calls;
    cin >> calls;
    cin.get();

    REP(i, 0, calls) {
        string line;
        getline(cin, line);
        REP(j, 0, line.size()) {
            if(line[j] == '(' || line[j] == ')' || line[j] == ',')
                line = line.substr(0, j) + ' ' + line.substr(j+1);
        }

        stringstream ss(line);
        string name, param;
        ss >> name;
        vs param_list;
        while(ss >> param) {
            //D(param);
            param_list.push_back(types[param]);
        }

        int cnt = 0;
        FOREACH(opt, procedures[name]) {
            if(opt->size() != param_list.size()) continue;
            bool ok = true;
            //D(*opt); D(param_list);
            REP(k, 0, param_list.size()) {
                if((*opt)[k] == "T") continue;
                if(param_list[k] != (*opt)[k]) {
                    ok = false;
                    break;
                }
            }
            if(ok) cnt++;
        }
        cout << cnt << endl;
    }
}

