#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

struct p {
  int ind;
  double x, y;
};

double d(p a, p b) {
  double x = (a.x - b.x) * (a.x - b.x);
  double y = (a.y - b.y) * (a.y - b.y);
  return sqrt(x + y);
}

p white;
bool comp(p i, p j) {
  double a = d(i, white);
  double b = d(j, white);

  if (fabs(a - b) <= 0.001) return i.ind < j.ind;
  return a < b;
}

int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    int n;
    cin >> n;

    cin >> white.x >> white.y;

    vector<p> v(n);
    for (int i = 0; i < n; ++i) {
      p ball;
      cin >> ball.x >> ball.y;

      ball.ind = i + 1;
      v[i] = ball;
    }

    sort(v.begin(), v.end(), comp);
    cout << v[0].ind << endl;
  }

  return 0;
}