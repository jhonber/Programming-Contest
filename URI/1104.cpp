#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b;
  while  (cin >> a >> b) {
    if (a + b == 0) break;
    set<int> st1;
    int x;
    for (int i = 0; i < a; ++i) {
      cin >> x;
      st1.insert(x);
    }
 
    set<int> st2;
    for (int i = 0; i < b; ++i) {
      cin >> x;
      st2.insert(x);
    }
 
    int t1 = (int)st1.size();
    int t2 = (int)st2.size();
    st1.insert(st2.begin(), st2.end());
    st2.insert(st1.begin(), st1.end());
 
    int d1 = abs(t1 - (int)st1.size());
    int d2 = abs(t2 - (int)st2.size());
 
    cout << min(d1, d2) << endl;
  }
 
  return 0;
}
