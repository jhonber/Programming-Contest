#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool check(string w) {
  for (int i = 0; i < w.size(); ++i) if (!isalpha(w[i])) {
    return false;
  }
  return true;
}

int main() {
  string s;

  stringstream ss;
  while (getline(cin, s)) {

    int len = s.size() - 1;
    if (s[len] == '.') {
      s = s.substr(0, len);
    }

    ss << s;

    int tot, sum;
    tot = sum = 0;

    string token;
    while (getline(ss, token, ' ')) {
      if (check(token) && token.size() > 0) {
        int n = token.size();
        sum += n;
        tot ++;
      }
    }

    if (tot > 0) {
      int avg = sum / tot;
      if (avg <= 3) cout << 250 << endl;
      else if (avg > 3 && avg <= 5) cout << 500 << endl;
      else cout << 1000 << endl;
    }
    else cout << 250 << endl;

    ss.clear();
  }

  return 0;
}