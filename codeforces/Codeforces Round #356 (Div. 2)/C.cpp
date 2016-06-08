// http://codeforces.com/contest/680/problem/C

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x << " = " << (x) << endl;

map<int, set<int>> divs;
vector<int> paila(200, 0);

vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

void gen() {
  for (int i = 2; i <= 100; ++i) {
    int j = 2;
    while (j * j <= i) {
      if (i % j == 0) {
        divs[i].insert(j);
        divs[i].insert(i / j);
      }
      j ++;
    }

    if (divs[i].size() == 0) divs[i].insert(i);
  }
}

bool is_prime(int x) {
  for (int i = 0; i < primes.size(); ++i) if (primes[i] == x) return true;
  return false;
}

int main() {
  gen();
/*
  for (int i = 2; i <= 100; ++i) {
    cout << i << ": ";
    set<int> st = divs[i];
    for (auto j: st) cout << j << " ";
    cout << endl;
  }
*/
  string res;
  int cnt = 0;
  int lim = 20;
  for (int i = 2; i <= 100 && lim > 0; ++i) {
    int cur = i;
    if (!paila[cur]) {
      cout << cur << endl;
      cin >> res;
      lim --;

      if (res == "yes") {
        for (int j = 2; j <= 100; ++j) {
          if (!paila[j] && divs[j].count(cur) == 0) paila[j] = true;
        }

        cnt ++;
      }
      else {
        paila[cur] = true;
        for (int j = 2; j <= 100; ++j) {
          if (!paila[j] && divs[j].count(cur) > 0) {
            paila[j] = true;
          }
        }
      }
    }
  }

//  for (int i = 2; i <= 100; ++i) cout << paila[i] << " "; cout << endl;

  if (cnt > 1) {
    cout << "composite" << endl;
  }
  else {
    int c = 0;
    for (int i = 2; i <= 100; ++i) {
      if (paila[i]) continue;
//      cout << i << endl;
      if (!is_prime(i)) c ++;
    }

    if (c == 0) cout << "prime" << endl;
    else cout << "composite" << endl;
  }

  return 0;
}