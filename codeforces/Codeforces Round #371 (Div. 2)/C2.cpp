// http://codeforces.com/contest/714/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

long long get_mask(string &s) {
  long long n = 0;
  long long mask = 1;
  for (int i = 0; i < s.size(); ++i) {
    int cur = s[i] - '0';
    if (cur % 2 != 0) {
      n ^= mask;
    }
    mask <<= 1;
  }

  return n;
}

void normalize (string &s) {
  while (s.size() < 18) s = "0" + s;
}

int main() {
  int t;
  cin >> t;

  unordered_map<long long, int> magic;

  while (t --> 0) {
    char op;
    string x;
    cin >> op >> x;

    normalize(x);

    long long mask = get_mask(x);
    if (op == '?') {
      cout << magic[mask] << endl;
    }
    else if (op == '+') {
      magic[mask] ++;
    }
    else {
      magic[mask] --;
    }
  }

  return 0;
}