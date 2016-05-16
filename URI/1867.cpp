#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

string to_str(int x) {
  string ans;
  stringstream ss;
  ss << x;
  ss >> ans;

  return ans;
}

void solve(string a, string b) {
  while (a.size() > 1) {
    int x = 0;
    for (int i = 0; i < a.size(); ++i) {
      x += int(a[i] - '0');
    }
    a = to_str(x);
  }

  while (b.size() > 1) {
    int x = 0;
    for (int i = 0; i < b.size(); ++i) {
      x += int(b[i] - '0');
    }
    b = to_str(x);
  }

  int aa = a[0] - '0';
  int bb = b[0] - '0';
  int ans = 0;
  if (aa > bb) ans = 1;
  else if (aa < bb) ans = 2;

  cout << ans << endl;
}

int main() {
  string a, b;

  while (cin >> a >> b) {
    if (a == "0" && b == "0") break;
    solve(a, b);
  }

  return 0;
}