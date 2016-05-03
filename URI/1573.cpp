#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b, c;
  while (cin >> a >> b >> c) {
    if (!a) break;

    int v1 = a * b * c;
    int i = 1;
    while (i * i * i < v1) i ++;

    if (i * i * i > v1) i --;

    cout << i << endl;
  }

  return 0;
}