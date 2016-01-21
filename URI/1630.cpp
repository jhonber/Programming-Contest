#include<bits/stdc++.h>
using namespace std;
 
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x)cout << #x << " = " << (x) << endl;
 
long long solve(long long a, long long b) {
  if (a < b) swap(a, b);
 
  long long x = 1;
  long long i = 2;
 
  while (i * i <= a) {
    if (a % i == 0) {
      if (b % i == 0) {
        x = max(x, i);
        if (b % (a / i) == 0) {
          x = max(x, a / i);
        }
      }
    }
    i ++;
  }
 
  if (a == b) return 4;
  if (a % b == 0) return (a * b) / b;
  return (2 * (a / x) + (2 * (b / x)));
}
 
int main() {
  long long x, y;
  while (cin >> x >> y) {
    cout << solve(x, y) << endl;
  }
 
  return 0;
}
