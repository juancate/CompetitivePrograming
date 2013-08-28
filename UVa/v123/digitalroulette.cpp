#include <bits/stdc++.h>

using namespace std;

const int MAXK = 10 + 1;
const int MAXN = (int)10e7 + 10;

int N, M, K;
int coeficients[MAXK];
bool numbers[MAXN];

int eval(int x) {
  long long ans = 0;
  long long power = 1;
  for (int i = 0; i <= K; i++) {
    ans = ans + (coeficients[i] * power) % (N + 1);
    power = (power * x) % (N + 1);
  }

  return (int)(ans % (N + 1));
}

int main() {
  while (scanf("%d %d", &N, &M)) {
    if ((N|M) == 0)
      break;

    scanf("%d", &K);

    for (int i = 0; i <= K; i++)
      scanf("%d", coeficients + i);

    memset(numbers, 0, N+1);

    int cnt = 0;
    for (int i = 0; i <= M; i++) {
      int px = eval(i);
      if (!numbers[px]) {
        cnt++;
        numbers[px] = true;
      }
    }

    printf("%d\n", cnt);
  }

  return 0;
}

