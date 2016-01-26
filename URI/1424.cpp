#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int n, m;
  while (cin >> n >> m) {
 
  map<int, vector<int> > v;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    v[a].push_back(i + 1);
  }
 
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b; a --;
    if (a < v[b].size()) cout << v[b][a] << endl;
    else cout << "0" << endl;
  }
  }
 
  return 0;
}
