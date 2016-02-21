#include<bits/stdc++.h>
using namespace std;

const int mx = (1 << 20) + 10;
double fact_dig[mx];

void gen (int mx) {
  double ans = 0;
  fact_dig[0] = ans;
  for (int i = 1; i < mx; ++i) {
    ans += log(i);
    fact_dig[i] = ans;
  }
}

int main() {
  gen(mx);

  int n, b;
  while (cin >> n >> b) {
    int num_dig = floor(fact_dig[n] / log(b)) + 1;

    int last_pri, last_exp;
    int bb = b;
    for (int p = 2; p <= bb; ++p) {
      if (bb % p == 0) {
        int exp = 0;
        while (bb % p == 0) {
          bb /= p;
          exp ++;
        }

        last_pri = p;
        last_exp = exp;
      }
    }

    int times = 0;
    while (n > 0) {
      n /= last_pri;
      times += n;
    }

    int tra_zeros = times / last_exp;
    cout << tra_zeros << " " << num_dig << endl;
  }

  return 0;
}
