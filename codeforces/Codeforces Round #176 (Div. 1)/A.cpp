// http://codeforces.com/contest/286/problem/A

#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL);

bool check (vector<int> &v, int &n) {
  for (int i = 0; i < n; ++i)
    if (v[v[i] - 1] != n - (i + 1) + 1) return false;
  return true;
}

int main() { FASTER
  int n;
  cin >> n;

  if (n == 1) cout << 1;
  else if (n == 2 || n == 3) cout << -1;
  else {
    vector<int> v(n, 0);
    int a = 2;
    int b = n;

    int i = 0;
    int j = n - 2;

    while (i < j) {
      v[i] = a;
      v[i + 1] = b;
      v[j] = a - 1;
      v[j + 1] = b - 1;

      a += 2;
      b -= 2;
      i += 2;
      j -= 2;
    }
    int mid = (n / 2);
    if (n % 2 == 0) {
      if (!v[mid - 1]) {
        v[mid - 1] = a;
        v[mid] = a - 1;
      }
    }
    else {
      if (!v[mid]) v[mid] = mid + 1;
    }

    if (check(v, n))
      for (int i = 0; i < n; ++i) cout << v[i] << " ";
    else
      cout << -1;
  }

  return 0;
}