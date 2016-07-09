#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios::sync_with_stdio(false); cin.tie(NULL);

char f (char c) {
  string s =  "jpsvbxz";
  string s2 = "JPSVBXZ";

  for (int i = 0; i < s.size(); ++i) if (c == s[i]) {
    return 'f';
  }

  for (int i = 0; i < s2.size(); ++i) if (c == s2[i]) {
    return 'F';
  }

  return c;
}

bool is_f (char c) {
  return c == 'f' || c == 'F';
}

int main() { IO
  string s;
  while (getline(cin, s)) {
    if (s == "") {
      cout << endl;
      continue;
    }

    for (int i = 0; i < s.size(); ++i) {
      s[i] = f(s[i]);
    }

    for (int i = 0; i < s.size(); ) {
      cout << s[i];
      if (is_f(s[i])) {
        i ++;
        while (i < s.size() && is_f(s[i])) i ++;
      }
      else i ++;
    }

    cout << endl;
  }

  return 0;
}