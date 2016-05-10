#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    int n;
    cin >> n;

    vector<int> steps;
    string s;
    int pos = 0;
    int id;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      if (s == "SAME") {
        cin >> s >> id;
        pos += steps[id - 1];
        steps.push_back(steps[id - 1]);
      }
      else {
        if (s == "LEFT") {
          steps.push_back(-1);
          pos --;
        }
        else {
          steps.push_back(1);
          pos ++;
        }
      }
    }

    cout << pos << endl;
  }

  return 0;
}