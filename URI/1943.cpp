#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  int n;
  cin >> n;

  vector<int> v = {1, 3, 5, 10, 25, 50, 100};
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] >= n) {
      cout << "Top " << v[i] << endl;
      break;
    }
  }

  return 0;
}