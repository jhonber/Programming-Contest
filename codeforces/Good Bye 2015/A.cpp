// http://codeforces.com/contest/611/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  char s[255];

  scanf("%d of %s", &n, &s);

  if (s[0] == 'w') {
    if (n == 5 || n == 6) cout << 53;
    else cout << 52;
  }
  else {
    if (n < 30) cout << 12;
    else if (n == 31) cout << 7;
    else cout << 11;
  }

  return 0;
}