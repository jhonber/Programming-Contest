#include<bits/stdc++.h>
using namespace std;

long long bin_to_dec(string n) {
  long long ans = 0;
  long long pot = 1;
  int i = n.size() - 1;

  while (i >= 0) {
    if (n[i] == '1') ans += pot;
    pot *= 2;
    i --;
  }

  return ans;
}


string dec_to_bin(long long n) {
  string ans;
  while (n > 0) {
    char c;
    if (n % 2 == 0) c = '0';
    else c = '1';
    ans.push_back(c);
    n /= 2;
  }

  reverse(ans.begin(), ans.end());
  return ans;
}

string dec_to_hex(long long n) {
  stringstream ss;
  string ans;
  ss << hex << n;
  ss >> ans;
  return ans;
}

string bin_to_hex(string n) {
  long long x = bin_to_dec(n);
  return dec_to_hex(x);
}

long long hex_to_dec(string n) {
  long long ans;
  stringstream ss;
  ss << n;
  ss >> hex >> ans;

  return ans;
}

string hex_to_bin(string n) {
  long long x = hex_to_dec(n);
  return dec_to_bin(x);
}

int main() {
  string a, b;
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    stringstream ss;
    ss << a;

    cout << "Case " << i + 1 << ":" << endl;
    if (b == "dec") {
      long long x;
      ss >> x;
      cout << dec_to_hex(x) << " hex" << endl;
      cout << dec_to_bin(x) << " bin" << endl;
    }
    else if (b == "bin") {
      cout << bin_to_dec(a) << " dec"<< endl;
      cout << bin_to_hex(a) << " hex" << endl;
    }
    else {
      cout << hex_to_dec(a) << " dec" << endl;
      cout << hex_to_bin(a) << " bin" << endl;
    }
    cout << endl;
  }

  return 0;
}
