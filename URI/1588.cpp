#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

struct team {
  string name;
  int pos, points, score, wins;

  bool operator < (const team & other) const {
    if (points == other.points) {
      if (wins == other.wins) {
        if (score == other.score) {
          return pos < other.pos;
        }
        return score > other.score;
      }
      return wins > other.wins;
    }
    return points > other.points;
  }
};

int find (vector<team> &v, string &name) {
  for (int i = 0; i < v.size(); ++i) {
    if (v[i].name == name) return i;
  }
}

int main() {
  int T;
  cin >> T;

  while (T --> 0) {
    int n, m;
    cin >> n >> m;

    vector<team> v(n);
    for (int i = 0; i < n; ++i) {
      string name;
      cin >> name;

      team t;
      t.pos = i;
      t.name = name;
      t.wins = 0;
      t.points = 0;
      t.score = 0;

      v[i] = t;
    }


    string n1, n2;
    int a, b;
    for (int i = 0; i < m; ++i) {
      cin >> a >> n1 >> b >> n2;

      int p1 = find(v, n1);
      int p2 = find(v, n2);

      v[p1].score += a;
      v[p2].score += b;

      if (a > b) {
        v[p1].points += 3;
        v[p1].wins ++;
      }
      else if (a < b) {
        v[p2].points += 3;
        v[p2].wins ++;
      }
      else {
        v[p1].points ++;
        v[p2].points ++;
      }
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
      cout << v[i].name << endl;
    }
  }

  return 0;
}