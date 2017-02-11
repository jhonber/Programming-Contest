// http://codeforces.com/contest/734/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int cnt = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'D') cnt ++;
  }

  if (cnt > s.size() - cnt) cout << "Danik" << endl;
  else if ( cnt < s.size() - cnt) cout << "Anton" << endl;
  else cout << "Friendship" << endl;

  return 0;
}