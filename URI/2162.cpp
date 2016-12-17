#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;


  int v[n + 1];
  for (int i = 0; i < n; ++i) cin >> v[i];

  if (n == 2){
    if (v[0] == v[1]) cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
  }

  v[n] = v[n - 2];

  int ok1 = true;
  int ok2 = true;
  for (int i = 1; i < n; i += 2) {
    if (!(v[i] > v[i - 1] && v[i] > v[i + 1])) ok1 = false;
    if (!(v[i] < v[i - 1] && v[i] < v[i + 1])) ok2 = false;
  }

  cout << ((!ok1 && !ok2) ? 0 : 1) << endl;

  return 0;
}