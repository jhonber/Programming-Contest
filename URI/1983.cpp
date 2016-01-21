#include<bits/stdc++.h>
using namespace std;
 
int main () {
  int n;
  cin >> n;
 
  pair<int, double> winer;
  winer.second = 0.0;
 
  for (int i = 0; i < n; ++i) {
    double a, b;
    cin >> a >> b;
    if (b > winer.second) {
      winer.first = a;
      winer.second = b;
    }
  }
 
  if (winer.second < 8.0) cout << "Minimum note not reached" << endl;
  else cout << winer.first << endl;
  return 0;
}
