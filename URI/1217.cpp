#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int cnt = 0, day = 1;
  double sum = 0, sum2 = 0;
  string s;

  while (cin >> s) {
    if (isalpha(s[0])) {
      cnt ++;
      sum2 ++;
    }
    else {
      double tmp;
      stringstream ss(s);
      ss >> tmp;
      sum += tmp;
      if (cnt > 0) {
        cout << "day " << day << ": " << cnt << " kg" << endl;
        day ++;
        cnt = 0;
      }
    }
  }

  cout << "day " << day << ": " << cnt << " kg" << endl;
  printf("%.2lf kg by day\n", (double)sum2 / day);
  printf("R$ %.2lf by day\n", sum / day);
  return 0;
}