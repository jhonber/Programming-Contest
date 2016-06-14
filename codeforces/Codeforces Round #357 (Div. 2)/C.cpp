// http://codeforces.com/contest/681/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

const int inf = 1e9 + 7;

struct query {
  string op;
  int val;
  query () {}
  query (string op_, int val_): op(op_), val (val_) {}
};

int main() {
  int n;
  cin >> n;

  vector<string> ope = {"insert", "getMin", "removeMin"};
  vector<query> ans;
  priority_queue<int, vector<int>, greater<int>> Q;

  int a;
  for (int i = 0; i < n; ++i) {
    string op;
    cin >> op;

    if (op != ope[2]) {
      cin >> a;

      if (op == ope[0]) {
        Q.push(a);
        ans.push_back(query(ope[0], a));
      }
      else {
        while (!Q.empty() && Q.top() < a) {
          Q.pop();
          ans.push_back(query(ope[2], inf));
        }

        if (!Q.empty() && Q.top() != a || Q.empty()) {
          Q.push(a);
          ans.push_back(query(ope[0], a));
        }

        ans.push_back(query(ope[1], a));
      }
    }
    else {
      int mx = 1e9;
      if (Q.empty()) {
        ans.push_back(query(ope[0], mx));
        ans.push_back(query(ope[2], inf));
      }
      else {
        Q.pop();
        ans.push_back(query(ope[2], inf));
      }
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i){
    cout << ans[i].op;
    if (ans[i].val != inf) cout << " " << ans[i].val;
    cout << endl;
  }

  return 0;
}