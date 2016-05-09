#include<bits/stdc++.h>
using namespace std;

int main() {
  string t, line;
  int t2;

  getline(cin, t);

  t2 = atoi(t.c_str());

  while (t2 --> 0) {
    getline(cin, line);

    for (int i = 0; i < line.size(); ++i) {
      if (isalpha(line[i]))
        line[i] = char((int)(line[i]) + 3);
    }

    reverse(line.begin(), line.end());

    for (int i = line.size() / 2; i < line.size(); ++i) {
      line[i] = char((int)(line[i]) - 1);
    }

    cout << line << endl;
  }

  return 0;
}