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

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

template<typename T,typename U> inline
std::ostream& operator<<(std::ostream& os, const pair<T,U>& z){
    return ( os << "(" << z.first << ", " << z.second << ",)" );
}
template<typename T> inline
std::ostream& operator<<(std::ostream& os, const vector<T>& z){
    os << "[ ";
    REP(i,0,z.size())os << z[i] << ", " ;
    return ( os << "]" << endl);
}
template<typename T> inline
std::ostream& operator<<(std::ostream& os, const set<T>& z){
    os << "set( ";
    FOREACH(p,z)os << (*p) << ", " ;
    return ( os << ")" << endl);
}
template<typename T,typename U> inline
std::ostream& operator<<(std::ostream& os, const map<T,U>& z){
    os << "{ ";
    FOREACH(p,z)os << (p->first) << ": " << (p->second) << ", " ;
    return ( os << "}" << endl);
}

const int INF = (int)(1e9);
const long long INFLL = (long long)(1e18);
const double EPS = 1e-13;

const int MAXN = 1000 + 10;

int T, N, indegree[MAXN];
vector< vector<int> > G;

bool bfs(int start) {
    vector<bool> visited(N, false);
    vector<int> inqueue(N, 0);
    queue<int> Q;
    Q.push(start);
    inqueue[start]++;

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        inqueue[u]--;

        if(visited[u] or inqueue[u] > 0) return true;
        visited[u] = true;

        FOREACH(v, G[u]) {
            Q.push(*v);
            inqueue[*v]++;
        }
    }
    return false;
}

int main() {
    scanf("%d", &T);
    REP(id, 1, T+1) {
        scanf("%d", &N);
        G.clear();
        G.resize(N);

        REP(i, 0, N) {
            scanf("%d", indegree + i);
            REP(j, 0, indegree[i]) {
                int x;
                scanf("%d", &x);
                G[--x].push_back(i);
            }
        }

        bool finded = false;
        
        REP(i, 0, N) if(indegree[i] == 0) {
            finded = bfs(i);
            if(finded) break;
        }

        printf("Case #%d: %s\n", id, (finded)? "Yes" : "No");
    }
}

