// http://codeforces.com/contest/760/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int m, d;
  cin >> m >> d;
  m --; d --;

  int days[] = {0, 1, 2, 3, 4, 5, 6};
  int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  cout << ceil((days[d] + months[m]) / 7.0) << endl;

  return 0;
}