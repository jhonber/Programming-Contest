#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool check(long long x) {
  if (x % 3 == 0) return true;
  while (x > 0) {
    if (x % 10 == 3) return true;
    x /= 10;
  }
  return false;
}

vector<long long> gen() {
  vector<long long> r;
  long long a, b;
  a = 1;
  b = 1;
  int cnt = 90;
  while (cnt --> 0) {
    long long tmp = a + b;
    if (check(a)) {
      r.push_back(a);
    }

    if (check(b)) {
      r.push_back(b);
    }

    a = b;
    b = tmp;
  }

  r.erase(unique(r.begin(), r.end()), r.end());
  return r;
}

int main() { IO
  vector<long long> v = gen();

  long long n;
  while (cin >> n) {
    cout << v[n - 1] << endl;
  }
}