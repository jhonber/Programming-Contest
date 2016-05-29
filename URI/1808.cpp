#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;
  cin >> s;

  double tot = 0;
  double sum = 0;
  int ind = s.find("10");
  while (ind != string::npos) {
    tot ++;
    sum += 10;
    s[ind] = s[ind + 1] = '*';
    ind = s.find("10", ind + 2);
  }

  for (int i = 0; i < s.size(); ++i) if (s[i] != '*') {
    sum += s[i] - '0';
    tot ++;
  }

  printf("%.2lf\n", sum / tot);

  return 0;
}