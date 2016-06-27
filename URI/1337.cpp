#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  vector<int> v(3);

  while (cin >> v[0] >> v[1] >> v[2]) {
    if (!v[0]) break;

    sort(v.begin(), v.end());

    if (v[0] == 13 && v[1] == 13 && v[2] == 13) {
      cout << "*" << endl;
    }
    else if (v[0] == 12 && v[1] == 13 && v[2] == 13) {
      cout << "1 1 1" << endl;
    }
    else if (v[2] == 13 && v[0] == v[1]) {
      if (v[0] == 12)
        cout << "1 13 13" << endl;
      else {
        cout << "1 " << v[0] + 1 << " " << v[0] + 1 << endl;
      }
    }
    else if (v[2] == 13 && v[1] == 13) {
      cout << v[0] + 1 << " 13 13" << endl;
    }
    else {
      if (v[0] == v[1] && v[1] == v[2]) {
        v[0] ++;
        cout << v[0] << " " << v[0] << " " << v[0] << endl;
      }
      else if (v[0] == v[1]) {
        if (v[0] == 12 && v[1] == 13) {
          cout << "1 13 13" << endl;
        }
        else if (v[2] == 13) {
          cout << "1 " << v[0] + 1 << " " << v[0] + 1 << endl;
        }
        else {
          cout << v[0] << " " << v[1] << " " << v[2] + 1 << endl;
        }
      }
      else if (v[1] == v[2]) {
        if (v[0] + 1 != v[1]) {
          cout << v[0] + 1 << " " << v[1] << " " << v[2] << endl;
        }
        else {
          if (v[0] + 2 <= 13) {
            v[0] += 2;
            sort(v.begin(), v.end());
            cout << v[0] << " " << v[1] << " " << v[2] << endl;
          }
          else {
            assert(false);
          }
        }
      }
      else {
        cout << "1 1 2" << endl;
      }
    }
  }

  return 0;
}