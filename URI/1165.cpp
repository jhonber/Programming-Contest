#include<bits/stdc++.h>
using namespace std;

#define D(x)cout << #x << " " << (x) << endl;

bool is_prime(int x) {
  if (x <= 2) return true;
  int i = 2;
  while (i * i <= x) {
    if (x % i == 0) return false;
    i ++;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  while (n --> 0) {
    int x;
    cin >> x;

    cout << x << " ";
    cout << (is_prime(x) ? "eh primo" : "nao eh primo") << endl;
  }

  return 0;
}