// http://codeforces.com/contest/711/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int n;
long long mat[555][555];

long long f1 (int x, int flag) {
  long long sum = 0;
  if (flag) {
    for (int i = 0; i < n; ++i) sum += mat[i][x];
  }
  else {
    for (int i = 0; i < n; ++i) sum += mat[x][i];
  }

  return sum;
}

long long f2 (int flag) {
  long long sum = 0;
  if (flag) {
    for (int i = 0; i < n; ++i) sum += mat[i][i];
  }
  else {
    int j = n - 1;
    for (int i = 0; i < n; ++i, --j) sum += mat[i][j];
  }

  return sum;
}

bool good () {
  long long sum;
  set<long long> st;
  for (int i = 0; i < n; ++i) {
    sum = f1(i, 0);
    st.insert(sum);
    sum = f1(i, 1);
    st.insert(sum);
  }

  sum = f2(0);
  st.insert(sum);
  sum = f2(1);
  st.insert(sum);

  if (st.size() == 1) return true;
  return false;
}

int main() {
  cin >> n;

  int x, y;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
      if (mat[i][j] == 0) {
        x = i;
        y = j;
      }
    }
  }

  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }

  long long sum;
  set<long long> st;
  for (int i = 0; i < n; ++i) {
    sum = f1(i, 0);
    st.insert(sum);
    sum = f1(i, 1);
    st.insert(sum);
  }

  sum = f2(0);
  st.insert(sum);
  sum = f2(1);
  st.insert(sum);

  if (st.size() != 2) cout << -1 << endl;
  else {
    auto it = st.begin();
    long long a = *it;
    it ++;
    long long b = *it;
    mat[x][y] = b - a;

    if (good ()) {
      cout << mat[x][y] << endl;
    }
    else cout << -1 << endl;;
  }
}