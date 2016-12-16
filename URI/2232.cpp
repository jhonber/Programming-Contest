#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  long long pascal[33][33];
  for (int i = 0; i < 33; ++i)
    for (int j = 0; j < 33; ++j)
      pascal[i][j] = 0;

  for (int i = 0; i < 33; ++i) pascal[i][0] = i + 1;
  for (int i = 0; i < 33; ++i) pascal[i][i] = 1;

  for (int i = 2; i < 33; ++i) {
    int cnt = i;
    while (cnt --> 1) {
      pascal[i][cnt] += pascal[i - 1][cnt] + pascal[i - 1][cnt - 1];
    }
  }

  int n;
  cin >> n;

  while (n --> 0) {
    int f;
    cin >> f;

    long long sum = 0;
    for (int i = 0; i < 33; ++i) sum += pascal[f - 1][i];
    cout << sum << endl;
  }


  return 0;
}