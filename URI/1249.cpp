#include<bits/stdc++.h>
using namespace std;

char f (char c) {
  int upp = false;
  if (isupper(c)) upp = true;

  c = tolower(c);
  int ind = ((c - 'a') + 13) % 26;
  char r = char(ind + 'a');
  if (upp) return toupper(r);
  return r;
}

int main() {
  string s;

  while (getline(cin, s)) {
    for (int i = 0; i < s.size(); ++i) {
      if (isalpha(s[i])) {
        s[i] = f(s[i]);
      }
    }

    cout << s << endl;
  }

  return 0;
}