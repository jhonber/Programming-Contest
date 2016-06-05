#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " < (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<int> divs;
  int i = 1;
  while (i * i <= n) {
    if (n % i == 0) {
      divs.push_back(i);
      divs.push_back(n / i);
    }

    i ++;
  }

  sort(divs.begin(), divs.end());
  for (int i = 0; i < divs.size(); ++i) cout << divs[i] << endl;

  return 0;
}