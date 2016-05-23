#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " " << (x) << endl;

int main() {
  int n = 15;
  vector<int> v1;
  vector<int> v2;
  while (n --> 0) {
    int x;
    cin >> x;

    if (x % 2 == 0) {
      v1.push_back(x);
    }
    else {
      v2.push_back(x);
    }

    if (v1.size() == 5) {
      for (int i = 0; i < v1.size(); ++i) {
        cout << "par[" << i << "] = " << v1[i] << endl;
      }
      v1.clear();
    }

    if (v2.size() == 5) {
      for (int i = 0; i < v2.size(); ++i) {
        cout << "impar[" << i << "] = " << v2[i] << endl;
      }
      v2.clear();
    }
  }


  for (int i = 0; i < v2.size(); ++i) {
    cout << "impar[" << i << "] = " << v2[i] << endl;
  }
  for (int i = 0; i < v1.size(); ++i) {
    cout << "par[" << i << "] = " << v1[i] << endl;
  }

  return 0;
}