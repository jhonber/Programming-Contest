#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string a;
  cin >> a;

  int tot = 0;
  for (int i = 0; i < a.size(); ++i) if (a[i] == '1') tot ++;

  cout << a << (tot % 2 != 0 ? "1" : "0") << endl;
}