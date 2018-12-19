#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
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
#define REP(i,n) for(int i=0; i<n; i++)
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
    REP(i,z.size())os << z[i] << ", " ;
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

const int INF = 1000000000;
const long long INFLL = 1000000000000000000LL;
const double EPS = 1e-13;

const int MAXN = 20 + 1;
vector<int> G[MAXN];
bool visited[MAXN];

int bfs(int start, int end) {
    queue< pair<int, int> > Q;
    Q.push(make_pair(start, 0));
    memset(visited, false, sizeof(visited));
    while(!Q.empty()) {
        pair<int, int> state = Q.front(); Q.pop();

        if(visited[state.first]) continue;
        if(state.first == end) return state.second;

        visited[state.first] = true;

        FOREACH(v, G[state.first]) {
            if(!visited[*v]) {
                Q.push(make_pair(*v, state.second + 1));
            }
        }
    }
    return -1;
}

int main() {
    int X, id = 1;
    while(true) {
        for(int i = 1; i <= 20; i++) G[i].clear();
        REP(i, 19) {
            if(scanf("%d", &X) != 1) return 0;
            REP(k, X) {
                int j;
                scanf("%d", &j);
                G[i+1].push_back(j);
                G[j].push_back(i+1);
            }
        }
        int N;
        scanf("%d", &N);
        printf("Test Set #%d\n", id);
        REP(i, N) {
            int start, end, ans;
            scanf("%d %d", &start, &end);
            ans = bfs(start, end);
            printf("%2d to %2d: %d\n", start, end, ans);
        }
        puts("");
        id++;
    }
}

