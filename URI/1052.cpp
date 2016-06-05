#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " < (x) << endl;

int main() {
  vector<string> m = {"January","February","March","April","May","June","July","August","September","October","November","December"};
  int n;
  cin >> n;

  cout << m[n - 1] << endl;
  return 0;
}