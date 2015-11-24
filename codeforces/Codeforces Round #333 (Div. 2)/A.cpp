// http://codeforces.com/contest/602/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cin.tie(false);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

long long mpow(int a, int b) {
  long long p = 1;
  while (b --> 0) p *= a;
  return p;
}

int main () {
  int n1, b1, n2, b2;
  cin >> n1 >> b1;

  long long num1 = 0;
  long long num2 = 0;

  int p = n1 - 1;
  for (int i = 0; i < n1; ++i) {
    long long t;
    cin >> t;
    num1 += t * mpow(b1, p);
    p --;
  }

  cin >> n2 >> b2;

  p = n2 - 1;
  for (int i = 0; i < n2; ++i) {
    long long t;
    cin >> t;
    num2 += t * mpow(b2, p);
    p --;
  }

  if (num1 > num2) cout << ">";
  else if  (num1 < num2) cout << "<";
  else cout << "=";

  return 0;
}