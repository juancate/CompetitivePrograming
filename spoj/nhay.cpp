#include <bits/stdc++.h>

using namespace std;

#define getcx getchar_unlocked

const int maxn = 10000100;

int m, n, b[maxn], ans[maxn];
char P[maxn];

void kmp_preprocess() {
  int i = 0, j = -1; b[0] = -1;
  while (i < m) {
    while (j >= 0 && P[i] != P[j]) j = b[j];
    i++; j++;
    b[i] = j;
  }
}

void kmp_search() {
  int i = 0, j = 0;
  char ch;
  while ((ch = getcx()) != '\n') {
    while (j >= 0 && ch != P[j]) j = b[j];
    i++; j++;
    if (j == m) {
      ans[n++] = i-j;
      j = b[j];
    }
  }
}

int main() {
  if (scanf("%d\n", &m) == EOF)
    return 0;

  while (true) {
    for (int i = 0; i < m; i++)
      P[i] = getcx();
    P[m] = 0;
    getcx();
    n = 0;

    kmp_preprocess();
    kmp_search();

    for (int i = 0; i < n; i++)
      printf("%d\n", ans[i]);

    if (scanf("%d\n", &m) != EOF) {
      if (n != 0)
        puts("");
    }
    else
      break;
  }

  return 0;
}
