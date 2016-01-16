// http://codeforces.com/contest/614/problem/B


#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x)cout << #x << " = " << (x) << endl;
int zeros = 0;

string mult(string a, string b) {
  if (a == "0" || b == "0") return "0";

  int len = 0;
  int ind = a.size() - 1;
  while (ind >= 0 && a[ind] == '0') {
    len ++;
    ind --;
  }

  zeros += len;
  a = a.substr(0, (a.size() - len));
  len = 0;
  ind = b.size() - 1;
  while (ind >= 0 && b[ind] == '0') {
    len ++;
    ind --;
  }

  zeros += len;
  b = b.substr(0, (b.size() - len));

  if (a == "1") return b;
  return a;
}

int main() {
  int n;
  cin >> n;

  string ans;
  cin >> ans;

  for (int i = 1; i < n; ++i) {
    string s;
    cin >> s;
    ans = mult(ans, s);
  }

  cout << ans;
  if (ans == "0") return 0;

  for (int i = 0; i < zeros; ++i) cout << "0";
  return 0;
}