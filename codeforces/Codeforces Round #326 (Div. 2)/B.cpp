// http://codeforces.com/contest/588/problem/B

#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

void getDivs(vector<long long> &v, long long n) {
  long long i = 1;
  while (i * i <= n) {
    if (n % i == 0) {
      v.push_back(i);
      v.push_back(n / i);
    }
    i ++;
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

int main() { IO
  long long n;
  cin >> n;

  vector<long long> divs;
  getDivs(divs, n);

  for (int i = divs.size() - 1; i >= 0; --i) {
    bool found = true;
    for (int j = 1; j < i; ++j) {
      long long a = divs[j];
      if (binary_search(divs.begin(), divs.end(), a * a) && divs[i] % (a * a) == 0) {
        found = false;
        break;
      }
    }

    if (found) {
      cout << divs[i];
      return 0;
    }
  }

  return 0;
}