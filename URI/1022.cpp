#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  int a, b, c, d;
  char op;
  for (int i = 0; i < n; ++i) {
    scanf("%d / %d %c %d / %d", &a, &b, &op, &c, &d);
    int num, den;

    if (op == '+') {
      int t1 = a * d;
      int t2 = b * c;
      num = t1 + t2;
      den = b * d;
    }
    else if (op == '-') {
      int t1 = a * d;
      int t2 = b * c;
      num = t1 - t2;
      den = b * d;
    }
    else if (op == '*') {
      num = a * c;
      den = b * d;
    }
    else {
      num = a * d;
      den = b * c;
    }

    int k = abs(__gcd(num, den));
    cout << num << "/" << den << " = ";
    num /= k;
    den /= k;

    cout << num << "/" << den << endl;
  }

  return 0;
}
