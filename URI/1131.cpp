#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b, c;
  int tot = 0;
  int ans1 = 0;
  int ans2 = 0;
  int emp = 0;

  while (cin >> a >> b) {
    cin >> c;
    cout << "Novo grenal (1-sim 2-nao)" << endl;
    tot ++;
    if (a > b) ans1 ++;
    else if (a < b) ans2 ++;
    else emp ++;
    if (c != 1) break;
  }

  cout << tot << " grenais" << endl;
  cout << "Inter:" << ans1 << endl;
  cout << "Gremio:" << ans2 << endl;
  cout << "Empates:" << emp << endl;

  if (ans1 > ans2) cout << "Inter venceu mais" << endl;
  else cout << "Gremio venceu mais" << endl;

  return 0;
}
