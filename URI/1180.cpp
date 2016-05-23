#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " " << (x) << endl;

int main() {
  int n;
  cin >> n;

  int ans = INT_MAX;
  int ind = 0;
  int pos = 0;
  while (n --> 0) {
    int a;
    cin >> a;
    if (a < ans) {
      ans = a;
      ind = pos;
    }

    pos ++;
  }

  cout << "Menor valor: " << ans << endl;
  cout << "Posicao: " << ind << endl;

  return 0;
}