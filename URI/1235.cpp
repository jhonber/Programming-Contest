#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string n2;
  getline(cin, n2);

  n = atoi(n2.c_str());

  for (int i = 0; i < n; ++i) {
    string line;
    getline(cin, line);
    int x = line.size() / 2.0;

    for (int j = x - 1, i = 0; i < line.size(); ++i, --j) {
      if (j < 0) j = line.size() - 1;
      cout << line[j];
    }
    cout << endl;
  }

  return 0;
}
