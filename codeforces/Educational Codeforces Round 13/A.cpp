// http://codeforces.com/contest/678/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  long long n, k;
  cin >> n >> k;

  long long i = ceil((double)n / k);
  if (n % k == 0) i ++;
  cout << k * i << endl;

  return 0;
}