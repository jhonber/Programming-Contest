// http://poj.org/problem?id=3219
#include<stdio.h>

int main () {
  int n, k;
  while (scanf("%d%d", &n, &k) != EOF) {
    printf("%d\n", !(k & (n - k)));
  }

  return 0;
}
