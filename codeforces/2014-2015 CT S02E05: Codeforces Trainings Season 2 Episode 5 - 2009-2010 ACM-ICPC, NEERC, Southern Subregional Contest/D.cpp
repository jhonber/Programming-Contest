// http://codeforces.com/gym/100503/problem/D

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

typedef unsigned long long ULL;

long long A, B, C;

long long f (long long xi) {
  return (A * xi + xi % B) % C;
}

int main() {
  #ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> A >> B >> C;
  long long a, b;
  a = f(1);
  b = f(f(1));

  int lim = 2 * 1e7;
  while (lim --> 0 && a != b) {
    a = f(a);
    b = f(f(b));
  }

  if (lim <= 0) {
    cout << -1 << endl;
    return 0;
  }

  int ind = 0; // Index of first repetition
  a = 1;
  while (a != b) {
    a = f(a);
    b = f(b);
    ind ++;
  }

  int size = 1; // Size of cycle
  b = f(a);
  while (a != b) {
    b = f(b);
    size ++;
  }

  cout << ind + size << endl;

  return 0;
}
