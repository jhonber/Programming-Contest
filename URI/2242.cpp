#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

bool vowel (char c) {
  return c == 'a' || c == 'e' || c== 'i' || c == 'o' || c == 'u';
}

int main() {
  string s;
  cin >> s;

  string a, b;
  for (int i = 0; i < s.size(); ++i) {
    char cur = tolower(s[i]);
    if (vowel(cur)) a.push_back(cur);
  }

  b = a;
  reverse(a.begin(), a.end());

  cout << (a == b ? 'S' : 'N') << endl;
  return 0;
}