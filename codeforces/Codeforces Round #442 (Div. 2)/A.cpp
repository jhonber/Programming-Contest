// http://codeforces.com/contest/877/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int count (string s, string name) {
  int cnt = 0;
  int ind = 0;
  while (ind < s.size()) {
    auto pos = s.find(name, ind);
    if (pos == string::npos) {
      break;
    }
    else {
      ind = pos + name.size();
      cnt ++;
    }
  }

  return cnt;
}

int main() {
  vector<string> names = {"Danil", "Olya", "Slava", "Ann", "Nikita"};

  string s;
  cin >> s;

  int ans[5] = {0, 0, 0, 0, 0};
  for (int i = 0; i < names.size(); ++i) {
    int t = count(s, names[i]);
    ans[i] = t;
  }

  int tot = 0;
  for (int i = 0; i < names.size(); ++i) {
    tot += ans[i];
  }


  cout << (tot == 1? "YES" : "NO") << endl;
  return 0;
}