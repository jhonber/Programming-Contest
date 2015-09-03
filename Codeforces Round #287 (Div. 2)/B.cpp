// http://codeforces.com/contest/507/problem/B

// Vega's code fixed
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r;
	int x, y; double nx, ny;

	cin >> r >> x >> y >> nx >> ny;

	double d = sqrt( (x-nx)*(x-nx) + (y-ny)*(y-ny) );

	cout << ceil(d/(2*r)) << endl;

	return 0;
}