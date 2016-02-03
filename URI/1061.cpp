#include<bits/stdc++.h>
using namespace std;

vector<int> read() {
  vector<int> v;
  for (int i = 0; i < 7; ++i) {
    string s;
    cin >> s;

    if (!isalpha(s[0]) && s[0] != ':') {
      stringstream ss(s);
      int n;
      ss >> n;
      v.push_back(n);
    }
  }

  return v;
}

int main() {
  vector<int> init = read();
  vector<int> end = read();

  int t[3] = {24, 60, 60};
  for (int i = 3; i > 0; --i) {
    if (init[i] <= end[i]) {
      end[i] = end[i] - init[i];
    }
    else {
      end[i] = (t[i - 1] - init[i]) + end[i];
      init[i - 1] ++;
    }
  }

  end[0] -= init[0];

  vector<string> s = {"dia(s)", "hora(s)", "minuto(s)", "segundo(s)"};
  for (int i = 0; i < 4; ++i) cout << end[i] << " " << s[i] << endl;
  return 0;
}
