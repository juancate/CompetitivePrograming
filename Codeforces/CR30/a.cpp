#include <bits/stdc++.h>

#define D(x) cerr << #x << " = " << x << endl

using namespace std;

int pow(int x, int n) {
  int p = 1;
  for(int i = 0; i < n; i++)
    p*=x;
  return p;
}

int main() {
  ios_base::sync_with_stdio(false);

  int A, B, n;
  cin >> A >> B >> n;

  if(A == 0) {
    if(B == 0)
      cout << 1 << endl;
    else
      cout << "No solution" << endl;
    return 0;
  }

  bool neg = A < 0;
  bool negB = B < 0;

  if(neg) A = -A;
  if(negB) B = -B;

  int X = round(exp(log(B / A) / n));
  D(X);

  if(neg) A = -A;
  if(negB) B = -B;

  if(neg && !negB) X = -X;
  else if(!neg && negB) X = -X;

  if((A * pow(X, n)) != B)
    cout << "No solution" << endl;
  else
    cout << X << endl;

  return 0;
}
