// http://codeforces.com/contest/460/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

pair<int, int> query (vector<int> &mm, vector<int> &cnt, vector<int> &ind) {
  int mmin = INT_MAX;
  int index = 0;

  for (int i = 0; i < mm.size(); ++i) {
    if (mm[i] + cnt[i] < mmin) {
      mmin = mm[i] + cnt[i];
      index = ind[i];
    }
  }

  return {mmin, index};
}

void update (vector<int> &v, vector<int> &mm, vector<int> &ind, int x, int a, int b) {
  int mmin = INT_MAX;
  int index = 0;
  for (int i = a; i <= b && i < v.size(); ++i) {
    if (v[i] < mmin) {
      mmin = v[i];
      index = i;
    }
  }

  ind[x] = index;
  mm[x]  = mmin;
}

void add (vector<int> &v, vector<int> &mm, vector<int> &cnt, vector<int> &ind, int size, int l, int r) {
  int pos = 0;
  for (int i = 0; i < mm.size(); ++i) {
    int a = pos;
    int b = pos + size - 1;

    if (a >= l && b <= r) {
      cnt[i] ++;
    }
    else if (l >= a && l <= b) {
      for (int j = l; j <= min(b, r) && j < v.size(); ++j) {
        v[j] ++;
      }

      update (v, mm, ind, i, a, b);
    }
    else if (r >= a && r <= b) {
      for (int j = a; j <= min(b, r) && j < v.size(); ++j) {
        v[j] ++;
      }

      update (v, mm, ind, i, a, b);
    }

    pos += size;
  }
}

int main() {
  int n, m, w;
  cin >> n >> m >> w;

  int size = ceil(sqrt(n));
  int size2 = ceil((double)n / size);

  vector<int> v(n), mm(size), cnt(size), ind(size);

  for (int i = 0; i < n; ++i) cin >> v[i];

  int pos = 0;
  for (int i = 0; i < size; ++i) {
    int mmin = INT_MAX;
    int index = 0;
    int b = pos + size2;
    for (int j = pos; j < b && j < v.size(); ++j) {
      if (v[j] < mmin) {
        mmin = v[j];
        index = j;
      }
    }

    mm[i]  = mmin;
    ind[i] = index;
    pos += size2;
  }

  for (int i = 0; i < m; ++i) {
    pair<int, int> p = query(mm, cnt, ind);

    int l = p.second;
    int r = l + w;

    r --;
    add (v, mm, cnt, ind, size2, l, r);
  }

  pair<int, int> p = query(mm, cnt, ind);
  cout << p.first << endl;

  return 0;
}