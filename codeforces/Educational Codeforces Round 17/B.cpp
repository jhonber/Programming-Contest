// http://codeforces.com/contest/762/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int m;
  cin >> m;

  vector<int> usb, ps2;
  while (m --> 0) {
    int p;
    string t;

    cin >> p >> t;
    if (t == "USB") usb.push_back(p);
    else ps2.push_back(p);
  }

  sort(usb.begin(), usb.end());
  sort(ps2.begin(), ps2.end());

  reverse(usb.begin(), usb.end());
  reverse(ps2.begin(), ps2.end());

  int tot = 0;
  long long price = 0;

  while (usb.size() > 0 && a > 0) {
    int cur = usb.back();
    usb.pop_back();
    price += cur;
    tot ++;
    a --;
  }

  while (ps2.size() > 0 && b > 0) {
    int cur = ps2.back();
    ps2.pop_back();
    price += cur;
    tot ++;
    b --;
  }

  usb.insert(usb.end(), ps2.begin(), ps2.end());
  sort(usb.begin(), usb.end());
  reverse(usb.begin(), usb.end());

  while (usb.size() > 0 && c > 0) {
    int cur = usb.back();
    usb.pop_back();
    price += cur;
    tot ++;
    c --;
  }

  cout << tot << " " << price << endl;

  return 0;
}