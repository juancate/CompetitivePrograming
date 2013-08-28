#include <cstdio>
#include <cstdlib>
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

const int INF = 100000000;
const long long INFLL = 1000000000000000000LL;
const double EPS = 1e-13;

// 706 - LC-Display
// Algorithm: Ad-hoc
// Protip: test corner cases if possible

using namespace std;

string numbers[5][10] = {{" - ","   "," - "," - ","   "," - "," - "," - "," - "," - "},
                         {"| |","  |","  |","  |","| |","|  ","|  ","  |","| |","| |"},
                         {"   ","   "," - "," - "," - "," - "," - ","   "," - "," - "},
                         {"| |","  |","|  ","  |","  |","  |","| |","  |","| |","  |"},
                         {" - ","   "," - "," - ","   "," - "," - ","   "," - "," - "}};

int S, M;
char N[10];

void println(int i, int j) {
  printf("%c", numbers[i][j][0]);
  for(int k = 0; k < S; k++) 
    printf("%c", numbers[i][j][1]);
  printf("%c", numbers[i][j][2]);
}

int main() {
  while(scanf("%d %s", &S, N) == 2 and (S|N[0]-'0') != 0) {
    M = strlen(N);
    for(int i = 0; i < 5; i++) {
      for(int j = 0; j < M; j++) {
        if(j) printf(" ");
        println(i, N[j] - '0');
      }
      puts("");
      if(i % 2 != 0) {
        for(int k = 0; k < S-1; k++) {
          for(int j = 0; j < M; j++) {
            if(j) printf(" ");
            println(i, N[j] - '0');
          } 
          puts("");
        }
      }
    }
    puts("");
  }
}

