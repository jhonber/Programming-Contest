// http://codeforces.com/contest/672/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  string all;
  stringstream ss;

  string cur;
  int k = 1;
  for (int i = 0; i < 1100; ++i) {
    ss.clear();
    ss << k;
    ss >> cur;
    all += cur;
    k ++;
  }


  cout << all[n - 1] << endl;
  return 0;
}