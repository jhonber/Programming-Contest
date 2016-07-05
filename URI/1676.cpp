#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

vector<int> seq;

void gen () {
  int mx = 40000;
  set<int> Q;
  for (int i = 2; i <= mx; ++i) Q.insert(i);

  set<int> :: iterator it;
  while (Q.size() > 0) {
    int cur = *Q.begin();
    seq.push_back(cur);

    it = Q.begin();
    int i = 0;
    vector<int> v;
    while (i < Q.size()) {
      if (i % cur == 0) {
        v.push_back(*it);
      }
      it ++;
      i ++;
    }

    for (int i = 0; i < v.size(); ++i) Q.erase(v[i]);
  }
}

int main() {
  gen();

  int n;
  while (cin >> n) {
    if (!n) break;

    cout << seq[n - 1] << endl;
  }

  return 0;
}