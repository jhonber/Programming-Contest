// http://codeforces.com/contest/803/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool f (int size, vector<int> &v, int &k) {
  int ind = 0;
  int parts = 0;

  while (ind < v.size()) {
    int cnt = 0;
    if (v[ind] > size) return false;

    while  (ind < v.size() && cnt + v[ind] <= size) {
      cnt += v[ind];
      ind ++;
    }

    parts ++;
  }

  return parts <= k;
}

int main() {
  string line;
  getline(cin, line);

  int k = atoi(line.c_str());

  getline(cin, line);

  for (int i = 0; i < line.size(); ++i) {
    if (line[i] == '-') line[i] = ' ';
  }

  stringstream ss;
  ss << line;

  vector<int> v;
  for (string token; getline(ss, token, ' '); ) {
    v.push_back(token.size() + 1);
  }

  v[v.size() - 1] --;

  int lo = 1;
  int hi = 1e6 + 10;
  int mid;

  while (lo < hi) {
    mid = (lo + hi) / 2;
    if (f(mid, v, k)) {
      hi = mid;
    }
    else {
      lo = mid + 1;
    }
  } 

  cout << lo << endl;

  return 0;
}