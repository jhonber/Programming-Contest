// http://codeforces.com/contest/630/problem/D

#include<bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;

  cout <<  6LL * ((n * (n + 1)) / 2LL) + 1 << endl;
}