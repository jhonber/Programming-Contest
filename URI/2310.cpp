#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main () {
  int n;
  cin >> n;

  vector<int> v(3, 0), vv(3, 0);
  while (n --> 0) {
    string name;
    cin >> name;

    int a, b, c;
    cin >> a >> b >> c;

    v[0] += a;
    v[1] += b;
    v[2] += c;

    cin >> a >> b >> c;

    vv[0] += a;
    vv[1] += b;
    vv[2] += c;
  }

  double a = vv[0] * 100. / v[0];
  double b = vv[1] * 100. / v[1];
  double c = vv[2] * 100. / v[2];

  cout << fixed << setprecision(2);
  cout << "Pontos de Saque: " << a << " %." << endl;
  cout << "Pontos de Bloqueio: " << b << " %." << endl;
  cout << "Pontos de Ataque: " << c << " %." << endl;

  return 0;
}