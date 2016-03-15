#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;


int gcd (int a, int b) {
  int tmp;
  while (b) {
    a %= b;
    tmp = a;
    a = b;
    b = tmp;
  }
  return a;
}


int lcm (int a, int b) {
  return a / gcd (a, b) * b;
}

int main() {
  long long n, a, b;
  while (cin >> n >> a >> b) {
    if (!n) break;
    long long ans = 0;
    ans += n / a;
    ans += n / b;
    ans -= n / lcm(a,b);

    cout << ans << endl;
  }
  return 0;
}