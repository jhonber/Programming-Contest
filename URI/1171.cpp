#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  map<int, int> mapa;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    mapa[a] ++;
  }

  for (auto i : mapa) {
    cout << i.first <<" aparece " << i.second << " vez(es)" << endl;
  }
}
