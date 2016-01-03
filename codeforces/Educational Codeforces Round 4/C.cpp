// http://codeforces.com/contest/612/problem/C

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cie.tie(false);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool check (char c) {
  return c == '<' || c == '{' || c == '(' || c == '[';
}

bool check2 (char a, char b) {
  if (a == '<' && b == '>') return true;
  if (a == '{' && b == '}') return true;
  if (a == '(' && b == ')') return true;
  if (a == '[' && b == ']') return true;
  return false;
}

void solve (string s) {
  vector<char> Q;
  if ( !check(s[0]) ) {
    cout << "Impossible";
  }
  else {
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      if ( check(s[i]) ) Q.push_back(s[i]);
      else {
        char last;

        if (Q.size() > 0) {
          last = Q[Q.size() - 1];
          Q.pop_back();
        }
        else {
          cout << "Impossible";
          return;
        }

        if ( !check2(last, s[i]) ) {
          ans ++;
        }
      }
    }

    if (Q.size() > 0) cout << "Impossible";
    else cout << ans;
  }
}


int main() {
  string s;
  cin >> s;

  solve(s);
  return 0;
}