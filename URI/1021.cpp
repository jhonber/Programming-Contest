#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  double x;
  cin >> x;

  long long n = x * 100LL;
  vector<long long> v1 = {10000, 5000, 2000, 1000, 500, 200};
  vector<long long> v2 = {100, 50, 25, 10, 5, 1};

  cout << fixed << setprecision(2);
  cout << "NOTAS:" << endl;
  for (int i = 0; i < v1.size(); ++i) {
    long long p = n / v1[i];
    n -= p * v1[i];
    cout << p << " nota(s) de R$ " << (v1[i] / 100.0) << endl;
  }

  cout << "MOEDAS:" << endl;
  for (int i = 0; i < v2.size(); ++i) {
    long long p = n / v2[i];
    n -= p * v2[i];
    cout << p << " moeda(s) de R$ " << (v2[i] / 100.0) << endl;
  }
  return 0;
}