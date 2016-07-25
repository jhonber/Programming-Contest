// http://codeforces.com/problemset/gymProblem/100971/G

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b, a1, b1, a2, b2;
  cin >> a >> b >> a1 >> b1 >> a2 >> b2;

  string ans = "NO";
  if (a1 <= a && b1 <= b) {
    int x  = a - a1, y = b;
    int x2 = b - b1, y2 = a;

    if (a2 <= x && b2 <= y) {
      ans = "YES";
    }

    swap(x, y);

    if (a2 <= x && b2 <= y) {
      ans = "YES";
    }

    if (a2 <= x2 && b2 <= y2) {
      ans = "YES";
    }

    swap(x2, y2);

    if (a2 <= x2 && b2 <= y2) {
      ans = "YES";
    }
  }

  swap(a, b);

  if (a1 <= a && b1 <= b) {
    int x  = a - a1, y = b;
    int x2 = b - b1, y2 = a;

    if (a2 <= x && b2 <= y) {
      ans = "YES";
    }

    swap(x, y);

    if (a2 <= x && b2 <= y) {
      ans = "YES";
    }

    if (a2 <= x2 && b2 <= y2) {
      ans = "YES";
    }

    swap(x2, y2);

    if (a2 <= x2 && b2 <= y2) {
      ans = "YES";
    }
  }

  cout << ans << endl;
  return 0;
}
