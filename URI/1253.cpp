#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  int n;
  string s;
  while (t --> 0) {
    cin >> s >> n;

    for (int i = 0; i < s.size(); ++i) {
      int ind = (s[i] - 'A') - n;
      ind += 26;
      ind %= 26;
      s[i] = char(ind + 'A');
    }

    cout << s << endl;
  }

  return 0;
}