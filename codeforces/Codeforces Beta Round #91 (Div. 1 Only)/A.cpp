// http://codeforces.com/contest/121/problem/A

#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

vector<long long> v;

void lucky (long long x) {
  if (x > 6 * 1e9) return;

  v.push_back(x);

  lucky(x * 10 + 4);
  lucky(x * 10 + 7);
}

int main() {
  lucky(0);
  sort(v.begin(), v.end());

  long long l, r;
  cin >> l >> r;

  long long sum = 0;
  for (int i = 1; i < v.size(); ++i) {
    long long a = v[i - 1] + 1;
    long long b = v[i];

    if (l >= a && r <= b) {
      sum += v[i] * ((r - l) + 1);
    }
    else if (a >= l && b <= r) {
      sum += v[i] * ((b - a) + 1);
    }
    else if (a >= l && a <= r) {
      sum += v[i] * ((r - a) + 1);
    }
    else if (b >= l && b <= r) {
      sum += v[i] * ((b - l) + 1);
    }
  }

  cout << sum << endl;

  return 0;
}