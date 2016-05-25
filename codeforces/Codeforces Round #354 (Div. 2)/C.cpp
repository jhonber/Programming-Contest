// http://codeforces.com/contest/676/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, k;
  cin >> n >> k;

    string s;
  cin >> s;

  int i = 0, j = 0;
  int b = 0;
  int ans1 = 0;
  while (i < n && j < n) {
    if (s[j] == 'a') j ++;
    else if (b + 1 <= k) {
      b ++;
      j ++;
    }
    else {
      ans1 = max(ans1, j - i);
      while (s[i] == 'a') i ++;
      if (s[i] == 'b') i ++;
      b --;
    }

    ans1 = max(ans1, j - i);
  }

  i = j = 0;
  int a = 0;
  int ans2 = 0;
  while (i < n && j < n) {
    if (s[j] == 'b') j ++;
    else if (a + 1 <= k) {
      a ++;
      j ++;
    }
    else {
      ans2 = max(ans2, j - i);
      while (s[i] == 'b') i ++;
      if (s[i] == 'a') i ++;
      a --;
    }

    ans2 = max(ans2, j - i);
  }

  cout << max(ans1, ans2) << endl;
  return 0;
}