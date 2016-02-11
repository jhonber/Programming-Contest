// http://codeforces.com/contest/622/problem/B

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

struct date{
  int h, m;
};

void count(date init, int a) {
  for (int i = 0; i < a; ++i) {
    init.m ++;
    if (init.m == 60) {
      init.h ++;
      init.m = 0;
    }

    if (init.h == 24) init.h = 0;
  }

  if (init.h < 10) {
    cout << "0" << init.h;
  }
  else cout << init.h;
  cout << ":";

  if (init.m < 10) {
    cout << "0" << init.m;
  }
  else cout << init.m;
  cout << endl;
}

int main () {
  int x, y;
  scanf("%d:%d", &x, &y);

  int a;
  cin >> a;

  date init;
  init.h = x;
  init.m = y;

  count(init, a);
  return 0;
}