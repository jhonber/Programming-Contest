#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;
  getline(cin, s);

  if (s.size() <= 140) cout << "TWEET" << endl;
  else cout << "MUTE" << endl;
  return 0;
}