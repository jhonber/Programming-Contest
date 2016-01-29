#include<bits/stdc++.h>
using namespace std;
 
int main() {
  for (int i = 0; i < 9; ++i) {
    for (int j = 7; j >= 5; --j)
      cout << "I=" << i + 1 << " J=" << j << endl;
    i ++;
  }
 
  return 0;
}
