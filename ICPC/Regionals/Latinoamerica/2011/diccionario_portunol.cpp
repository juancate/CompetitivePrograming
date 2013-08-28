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
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

struct Trie {
    int words;
    Trie* edges[26];
};

void initialize(Trie* vertex) {
    vertex->words = 0;

    for(int i = 0; i < 26; i++)
        vertex->edges[i] = NULL;
}

void addWord(Trie* vertex, const char* word, int& prefix_count) {
    if(*word == 0) {
        vertex->words++;
    }
    else {
        int k = (*word - 'a');
        
        if(vertex->edges[k] == NULL) {
            vertex->edges[k] = new Trie;
            initialize(vertex->edges[k]);
            prefix_count++;            
        }
        addWord(vertex->edges[k], ++word, prefix_count);
    }
}

int preffix_count, suffix_count;
int64 starts_with[26];
string buffer;

int64 suffix_dfs(Trie* u, int depth) {
    for(int i = 0; i < 26; i++) {
        if(u->edges[i] == NULL) continue;
        
        if(depth > 0)
            starts_with[i]++;
        
        suffix_dfs(u->edges[i], depth + 1);
    }
}

int64 preffix_dfs(Trie* u, int depth) {
    int64 ans = 0;
    if(depth > 0) ans += suffix_count;
    
    for(int i = 0; i < 26; i++) {
        if(u->edges[i] == NULL) {
            continue;
        }
        
        if(depth > 0)
            ans -= starts_with[i];

        ans += preffix_dfs(u->edges[i], depth + 1);
    }
    
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("diccionario.in", "r", stdin);
    freopen("diccionario.out", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
#endif
    
    int P, S;
    while(cin >> P >> S) {
        if((P|S) == 0) break;
        
        Trie preffix, suffix;
        initialize(&preffix);
        initialize(&suffix);
        
        preffix_count = suffix_count = 0;
        
        for(int i = 0; i < P; i++) {
            //gets(buffer);
            cin >> buffer;
            addWord(&preffix, buffer.c_str(), preffix_count);
        }

        for(int i = 0; i < S; i++) {
            //gets(buffer);
            cin >> buffer;
            reverse(ALL(buffer));
            addWord(&suffix, buffer.c_str(), suffix_count);
        }

        memset(starts_with, 0, sizeof(starts_with));
        
        suffix_dfs(&suffix, 0);
        int64 ans = preffix_dfs(&preffix, 0);

        cout << ans << endl;
    }
}
