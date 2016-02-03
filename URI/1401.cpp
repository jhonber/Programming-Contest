#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() { IO
  int n;
  cin >> n;

  string s;
  int f = false;
  while (n --> 0) {
    if (f) cout << endl;

    cin >> s;
    sort(s.begin(), s.end());

    do {
      cout << s << endl;
    }
    while (next_permutation(s.begin(), s.end()));

    f = true;
  }
  cout << endl;
  return 0;
}