#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    long long a, b;
    cin >> a >> b;

    long long tot = (a * b) - 1;
    if (tot % 2 == 0) cout << "Hussain" << endl;
    else cout << "Hasan" << endl;
  }

  return 0;
}
