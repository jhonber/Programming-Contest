// http://codeforces.com/contest/616/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cie.tie(false);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

void check(string a, string b) {
  int i = 0, j = 0;
  while (a[i] == '0') i ++;
  while (b[j] == '0') j ++;

  a = a.substr(i);
  b = b.substr(j);

  if (a.size() > b.size()) {
    cout << ">";
    return;
  }

  if (a.size() < b.size()) {
    cout << "<";
    return;
  }

  if (a == b) {
   cout << "=";
    return;
  }

  i = 0;
  while (i < a.size()) {
    if (a[i] - '0' > b[i] - '0') {
      cout << ">";
      return;
    }
    else if (a[i] - '0' < b[i] - '0') {
      cout << "<";
      return;
    }
    i ++;
  }
}

int main() {
  string a, b;
  cin >> a >> b;
  check(a, b);

  return 0;
}