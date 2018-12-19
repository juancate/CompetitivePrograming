#include <bits/stdc++.h>

using namespace std;

int a[111], n;

int getsize(int x) {
  int cnt = 0;
  while(x > 0) {
    x /= 10;
    cnt++;
  }
  return cnt;
}

void print_improper() {
  int num = 0;
  for(int i = 0; i < n; i++)
    num += a[i];
  int g = __gcd(abs(num), n);

  int b = num / g;
  int c = n / g;

  int a = abs(b) / c;
  b = b % c;

  int bsz = getsize(abs(b));
  int csz = getsize(c);
  int acz = getsize(a);

  int ln = max(bsz, csz);
  if(b < 0) printf("  ");

  for(int i = 0; i+bsz < ln+acz; i++)
    printf(" ");
  printf("%d\n", abs(b));
  if(b < 0) printf("- ");
  printf("%d", abs(a));
  for(int i = 0; i < ln; i++)
    printf("-");
  printf("\n");
  if(b < 0) printf("  ");
  for(int i = 0; i+csz < ln+acz; i++)
    printf(" ");
  printf("%d\n", abs(c));
}

void print_proper() {
  int num = 0;
  for(int i = 0; i < n; i++)
    num += a[i];
  int g = __gcd(abs(num), n);

  int b = num / g;
  int c = n / g;

  int bsz = getsize(abs(b));
  int csz = getsize(c);

  int ln = max(bsz, csz);

  if(b < 0) printf("  ");

  for(int i = 0; i < ln-bsz; i++)
    printf(" ");
  printf("%d\n", abs(b));
  if(b < 0) printf("- ");
  for(int i = 0; i < ln; i++)
    printf("-");
  printf("\n");
  if(b < 0) printf("  ");
  for(int i = 0; i < ln-csz; i++)
    printf(" ");
  printf("%d\n", abs(c));
}

int main() {
  int run = 1;
  while(scanf("%d", &n)) {
    if(n == 0)
      break;

    double avg = 0;
    int v = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", a+i);
      avg += a[i];
      v += a[i];
    }

    avg /= n;

    printf("Case %d:\n", run++);
    if(abs(v) % n == 0) {
      v /= n;
      if(v < 0) printf("- ");
      printf("%d\n", abs(v));
      continue;
    }

    if(fabs(avg) > 1)
      print_improper();
    else if(fabs(avg) < 1)
      print_proper();
  }
  return 0;
}
