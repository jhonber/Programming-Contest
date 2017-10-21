// http://codeforces.com/contest/841/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() { IO
  int n;
  while (cin >> n) {
    int odd = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      odd += x % 2;
      sum += x;
      sum %= 2;
    }

    if (odd > 1 || odd == 1 && sum) cout << "First" << endl;
    else cout << "Second" << endl;
  }

  return 0;
}