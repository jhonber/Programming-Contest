// https://www.hackerrank.com/challenges/cube-summation

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

string make_key (int x, int y, int z) {
  return to_string(x) + " " + to_string(y) + " " + to_string(z);
}

void decode_key (string key, int &x, int &y, int &z) {
  stringstream ss(key);

  string v;
  getline(ss, v, ' ');
  x = atoi(v.c_str());

  getline(ss, v, ' ');
  y = atoi(v.c_str());

  getline(ss, v, ' ');
  z = atoi(v.c_str());
}

int main() { IO
  int T;
  cin >> T;

  while (T --> 0) {
    unordered_map <string, long long> hash;

    int n, m;
    cin >> n >> m;

    string op;
    for (int i = 0; i < m; ++i) {
      cin >> op;
      if (op == "UPDATE") {
        int x, y, z, val;
        cin >> x >> y >> z >> val;
        hash[make_key(x, y, z)] = val;
      }
      else {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        long long ans = 0;
        for (auto j : hash) {
          int x, y, z, val = j.second;
          decode_key(j.first, x, y, z);

          if (x >= x1 && x <= x2 && y >= y1 && y <= y2 && z >= z1 && z <= z2) {
            ans += val;
          }
        }

        cout << ans << endl;
      }
    }
  }

  return 0;
}
