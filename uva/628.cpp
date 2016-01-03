#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int mpow(int a, int b) {
  int p = 1;
  while (b --> 0) {
    p *= a;
  }
  return p;
}

vector<string> gen(int n) {
  vector<string> ans;
  int pot = mpow(10, n);

  for (int i = 0; i < pot; ++i) {
    string t = toStr(i);
    while (t.size() < n) t = "0" + t;
    ans.push_back(t);
  }
  return ans;
}

void print(string rule, string s) {
  set<string> words;
  int cnt = 0;
  for (int i = 0; i < rule.size(); ++i) if (rule[i] == '0') cnt ++;
  vector<string> nums = gen(cnt);

  for (int i = 0; i < nums.size(); ++i) {
    string t;
    int ind = 0;
    for (int j = 0; j < rule.size(); ++j) {
      if (rule[j] == '#') t += s;
      else {
        t.push_back(nums[i][ind]);
        ind ++;
      }
    }
    words.insert(t);
  }

  for (auto i : words) {
    cout << i << endl;
  }
}

int main() { IO
  int n, m;
  while (cin >> n) {
    vector<string> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    cin >> m;
    vector<string> vv(m);
    for (int i = 0; i < m; ++i) cin >> vv[i];

    for (int i = 0; i < m; ++i) {
      cout << "--" << endl;
      for (int j = 0; j < n; ++j) {
        print(vv[i], v[j]);
      }
    }
  }

  return 0;
}
