#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  string line;
  getline(cin, line);

  n = atoi(line.c_str());

  while (n --> 0) {
    getline(cin, line);

    stringstream ss;
    ss << line;

    string ans;
    string word;

    while (ss >> word) {
      ans += word[0];
    }

    cout << ans << endl;
  }

  return 0;
}