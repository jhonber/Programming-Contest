// https://www.hackerrank.com/challenges/bitset-1

#include<bits/stdc++.h>
using namespace std;

// Bit array operations
#define set_bit(A, k) (A[k / 32] |= (1 << (k % 32)))
#define test_bit(A, k) (A[k / 32] & (1 << (k % 32)))
#define flip_bit(A, k) (A[k / 32] &= (1 << (k % 32)))
#define clear_bit(A, k) (A[k / 32] &= ~(1 << (k % 32)))

typedef unsigned long long ULL;

int main() {
  // Max int
  const int m = (1LL << 31) - 1;
  // Bit array
  vector<int> bit_array(m / 32);

  int n, s, p, q;
  cin >> n >> s >> p >> q;

  int tot = 1;
  ULL bef, next;
  bef = s & m;
  set_bit(bit_array, bef);

  for (int i = 1; i < n; ++i) {
    next = (bef * p + q) & m;
    if (!test_bit(bit_array, next)) {
      set_bit(bit_array, next);
      tot ++;
    }
    else break;

    bef = next;
  }

  cout << tot << endl;

  return 0;
}
