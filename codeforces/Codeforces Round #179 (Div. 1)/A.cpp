// http://codeforces.com/contest/295/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

class Fenwick{
	vector <long long> v;
	int maxSize;

	void add(int where, long long what){
		for (where++; where <= maxSize; where += where & -where){
			v[where] += what;
		}
	}

	public:
		Fenwick(int _maxSize) : maxSize(_maxSize+1){
			v = vector <long long>(maxSize, 0LL);
		}

		long long query(int where){
			long long sum = v[0];
			for (where++; where > 0; where -= where & -where){
				sum += v[where];
			}
			return sum;
		}

		void increase( int a, int b, long long what ) {
			add( a, what );
			add( b+1, -what );
		}

};


struct q {
  int x,y,d;
};

int main() { IO
  int n, m, k;
  cin >> n >> m >> k;

  Fenwick tree = Fenwick(n + 10000);

  vector<q> queries(m);

  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    tree.increase(i, i, t);
  }

  for (int i = 0; i < m; ++i) {
    q tmp;
    cin >> tmp.x >> tmp.y >> tmp.d;
    queries[i] = tmp;
  }

  Fenwick tree2 = Fenwick(m + 10000);

  for (int i = 0; i < k; ++i) {
    int a, b;
    cin >> a >> b;
    a --; b --;
    tree2.increase(a, b, 1);
  }

  for (int i = 0; i < m; ++i) {
    long long cnt = tree2.query(i);
    if (cnt) {
      int x = queries[i].x - 1;
      int y = queries[i].y - 1;
      long long d = queries[i].d * cnt;
      tree.increase(x, y , d);
    }
  }

  for (int i = 0; i < n; ++i) cout << tree.query(i) << " ";
  return 0;
}