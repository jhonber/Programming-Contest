#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

char f (char c) {
  if (c == 'O' || c == 'o') return '0';
  if (c == 'l') return '1';
  if (isdigit(c)) return c;
  if (c != ',' && c != ' ') return '#';
  return '*';
}

int main() {
  string line;
  while (getline(cin, line)) {

    string num;
    int paila = false;
    for (int i = 0; i < line.size(); ++i) {
      char x = f(line[i]);
      if (x != '*') num.push_back(x);
      if (line[i] == '-' || x == '#') paila = true;
    }

    reverse(num.begin(), num.end());
    while (num.size() > 1 && num.back() == '0') {
      num.pop_back();
    }

    reverse(num.begin(), num.end());

    long long n = 0;
    stringstream ss;
    ss << num;
    ss >> n;

    if (n < 0 || num.size() == 0 || num.size() > 10 || n > 2147483647 || paila)
      cout << "error" << endl;
    else
      cout << n << endl;
  }

  return 0;
}