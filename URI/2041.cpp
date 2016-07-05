#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios::sync_with_stdio(false); cin.tie(NULL);

vector<string> seq;

void f (string ant, int k) {
  if (k > 40) return;

  string next;
  int i = 0;
  while (i < ant.size()) {
    char cur = ant[i];

    int cnt = 0;
    while (i < ant.size() && ant[i] == cur) {
      i ++;
      cnt ++;
    }

    next.push_back(char(cnt + '0'));
    next.push_back(cur);
  }

  seq.push_back(next);

  f(next, k + 1);
}

int main() { IO
  seq.push_back("3");
  f ("3", 0);

  int n;
  while (cin >> n) {
    cout << seq[n - 1] << endl;
  }

  return 0;
}