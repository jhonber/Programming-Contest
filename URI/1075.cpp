#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= 10000; ++i) if ( i % n == 2) {
    printf("%d\n", i);
  }

  return 0;
}