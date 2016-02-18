// http://codeforces.com/contest/630/problem/L

#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  string n;
  n.push_back(s[0]);
  n.push_back(s[2]);
  n.push_back(s[4]);
  n.push_back(s[3]);
  n.push_back(s[1]);

  stringstream ss;
  ss << n;

  int n2;
  ss >> n2;

  int mod = 100000;
  int b = 5;
  long long p = 1;
  while (b --> 0) {
    p *= n2;
    p %= mod;
  }

  string ans;
  stringstream sss;
  sss << p;
  sss >> ans;

  while (ans.size() < 5) ans = "0" + ans;
  cout << ans;
  return 0;
}