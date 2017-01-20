// http://codeforces.com/contest/758/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int size (long long x) {
  if (!x) return 1;
  int c = 0;
  while (x) {
    x /= 10;
    c ++;
  }
  return c;
}

int main() {
  long long n;
  string k;

  cin >> n >> k;

  long long ans = 0;
  long long pot = 1;
  int tam = size(n);

  while (k.size() > 0) {
    long long num = 0;
    long long tmp = 0;
    long long p = 1LL;
    int times = 0;
    string k2 = k;
    while (k2.size() > 0) {
      tmp = p * (long long)(k2.back() - '0');
      if (num + tmp >= n || times > tam) break;
      num += tmp;
      k2.pop_back();
      times ++;
      p *= 10LL;
    }

    int tot = size(num);
    while (tot --> 0) k.pop_back();
    ans += pot * num;
    pot *= n;
  }

  cout << ans << endl;

  return 0;
}