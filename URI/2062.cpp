#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

string f(string s) {
  if (s.size() == 3) {
    int ind1 = s.find("OB");
    int ind2 = s.find("UR");
    if (ind1 == 0) return "OBI";
    if (ind2 == 0) return "URI";
  }
  return s;
}

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;
  cout << f(s);
  for (int i = 1; i < n; ++i) {
    cin >> s;
    cout << " " << f(s);
  }

  cout << endl;
  return 0;
}