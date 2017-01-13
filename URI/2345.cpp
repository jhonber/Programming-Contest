#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int v[] = {0, 0, 0 , 0};
  while (cin >> v[0] >> v[1] >> v[2] >> v[3]) {
    int mm = INT_MAX;

    do {
      mm = min(mm, abs((v[0] + v[1]) - (v[2] + v[3])));
    }
    while (next_permutation(v, v + 4));

    cout << mm << endl;
  }

  return 0;
}