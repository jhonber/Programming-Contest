#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < 1000; ++i) cout << "N[" << i << "] = " << i % n << endl;

  return 0;
}