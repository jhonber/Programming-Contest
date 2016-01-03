// http://codeforces.com/contest/608/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n,s;
  cin >> n >> s;

  map<int, int> mapa;
  for (int i = 0; i < n; ++i) {
    int a,b;
    cin >> a >> b;
    mapa[a] = max(mapa[a], b);
  }

  int ans = 0;
  int cnt = 0;
  for (int i = s; i > 0; --i) {
    if (mapa[i]) {
      if (cnt < mapa[i]) {
        cnt += mapa[i] - cnt;
      }
    }
    cnt ++;
  }

  cout << cnt;
  return 0;
}