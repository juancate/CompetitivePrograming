/**
 * Codeforces Round #105
 * Problem D
 * About: Probabilities, DP, memoization
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

const double eps = 1e-13;

double memo[1001][1001];
//bool visited[1001][1001];
//map<pair<int,int>, double> memo;

// Princess win recursion
double solve(int W, int B) {
  if(W <= 0) return 0; // no mice
  if(B <= 0) return 1; // no black mice

  if(memo[W][B] > -1) return memo[W][B];
  //pair<int, int> args = make_pair(W, B);
  //if(memo.find(args) != memo.end()) return memo[args];

  double ans = W * 1.0 / (W + B); // Probability of winning P=1.0 at this turn
  double cont_prob = B * 1.0 / (W + B); // Probability P to get to the state in next it
  B--; // There is one less black mice

  // Probability of continuing playing
  cont_prob = cont_prob * (B * 1.0) / (W + B);
  B--; // There is one less black mice

  // Now calculate the probability of a white or black mice jumping out
  if(cont_prob > eps) {
    double p_black = solve(W, B - 1) * (B * 1.0 / (W + B)); // solve = P of that state
    double p_white = solve(W - 1, B) * (W * 1.0 / (W + B));
    // Both events ocurr
    ans += cont_prob * (p_black + p_white); // Combine subproblems
  }
  memo[W][B+2] = ans;
  //visited[W][B] = true;
  //memo[args] = ans;
  return ans;
}

double solve2(int W, int B) {
  double dp[W+1][B+1];

  REP(i, W+1) dp[i][0] = 1;
  REP(i, B+1) dp[0][i] = 0;

  for(int i = 1; i < W+1; i++) {
    for(int j = 1; j < B+1; j++) {
      double ret = i * 1. / (i + j);
      double cont_prob = j * 1. / (i + j);
      cont_prob = cont_prob * ((j-1) * 1.) / (i + j - 1.);

      if(cont_prob > eps) {
        double p_black = dp[i][j-3] * (j - 2.) / (i + j - 2.);
        double p_white = dp[i-1][j-2] * (i * 1.) / (i + j - 2.);

        ret += cont_prob * (p_black + p_white);
      }
      dp[i][j] = ret;
    }
  }
  return dp[W][B];
}

int main() {
  int W, B;
  cin >> W >> B;

  //REP(i, 1001) REP(j, 1001) memo[i][j] = -1;
  double ans = solve2(W, B);
  printf("%.9lf\n", ans);
}
