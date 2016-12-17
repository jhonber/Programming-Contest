#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main () {
  int n;
  cin >> n;

  cout << fixed << setprecision(2);
  while (n --> 0) {
    string name;
    cin >> name;

    double a;
    cin >> a;

    vector<double> v(7);
    for (int i = 0; i < 7; ++i) cin >> v[i];

    sort(v.begin(), v.end());
    double tot = 0;
    for (int i = 1; i < 6; ++i) tot += v[i];
    cout << name << " " << tot * a << endl;
  }

  return 0;
}