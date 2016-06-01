#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  vector<int> v(11);
  string s;
  while (cin >> s) {
    for (int i = 0; i < s.size(); ++i) v[i] = s[i] - '0';

    int b1 = 0;
    for (int i = 0; i < s.size(); ++i) b1 += (i + 1) * v[i];

    int b2 = 0;
    for (int i = 0, j = 9; i < s.size(); ++i, --j) b2 += j * v[i];


    if (b1 % 11 == 10) b1 = 0;
    else b1 %= 11;


    if (b2 % 11 == 10) b2 = 0;
    else b2 %= 11;

    for (int i = 0; i < s.size(); ++i) {
      cout << s[i];
      if (i+1 < s.size() && (i+1) % 3 == 0) cout << ".";
    }

    cout << "-" << b1 << b2 << endl;

  }
  return 0;
}