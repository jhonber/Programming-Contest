#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int hp(double iv, double bhp, double ev, double l) {
  double num = iv + bhp + (sqrt(ev) / 8) + 50;
  num *= l;
  num /= 50;
  num += 10;
  return num;
}

int s (double iv, double bs, double ev, double l) {
  double num = iv + bs + (sqrt(ev) / 8);
  num *= l;
  num /= 50;
  num += 5;
  return num;
}

int main() {
  int t;
  cin >> t;

  vector<string> in = {"AT:", "DF:", "SP:"};
  for (int i = 0; i < t; ++i) {
    string name;
    int l;
    cin >> name >> l;

    cout << "Caso #" << i + 1 << ": " << name << " nivel " << l << endl;
    int bs, iv, ev;
    cin >> bs >> iv >> ev;
    cout << "HP: " << hp(iv, bs, ev, l) << endl;

    for (int i = 0; i < 3; ++i) {
      cin >> bs >> iv >> ev;
      cout << in[i] << " " << s(iv, bs, ev, l) << endl;
    }
  }

  return 0;
}