#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  long long a, b;
  while (cin >> a >> b) {
    if (a + b == 0) break;

    long long ans = a + b;
    string ans2;
    stringstream ss;
    ss << ans;
    ss >> ans2;

    for (int i = 0; i < ans2.size(); ++i) if (ans2[i] != '0') cout << ans2[i];
    cout << endl;
  }

  return 0;
}