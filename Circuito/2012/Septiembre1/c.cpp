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

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXN = 11;

int n, best;
int players[MAXN];

bool win(int i) {
    int cnt = 0;
    for(int j = 0; j < n; j++) {
        if(players[j]) {
            best = j;
        }
        else {
            cnt++;
        }
    }
    return cnt == n-1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int case_number = 0;

    while(cin >> n && n) {
        string game; cin >> game;

        int m = (int) game.size();

        fill(players, players+n, 3);

        int center = 0;
        int current = 0;
        bool winner = false;

        int i = 0;

        while(m - i >= min(3, players[current])) {
            if(win(current)) {
                winner = true;
                break;
            }

            int dices = min(3, players[current]);

            if(m - i < dices) {
                break;
            }

            for(int j = 0; j < dices; j++) {
                if(game[i+j] == '.') {
                    continue;
                }

                if(game[i+j] == 'C') {
                    center++;
                } else if(game[i+j] == 'L') {
                    int next = (current + 1) % n;
                    players[next]++;
                } else if(game[i+j] == 'R') {
                    int next = (current - 1 + n) % n;
                    players[next]++;
                }

                players[current]--;
            }

            i += dices;
            current = (current + 1) % n;
        }

        if(case_number) cout << endl;

        cout << "Game " << ++case_number << ":" << endl;

        for(i = 0; i < n; i++) {
            cout << "Player " << (i+1) << ":" << players[i];

            if(winner && best == i) {
                cout << "(W)";
            } else if(!winner && current == i) {
                cout << "(*)";
            }

            cout << endl;
        }
        cout << "Center:" << center << endl;
    }
}

