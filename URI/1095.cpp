#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b;
  a = 1; b = 60;
 
  while ( b >= 0) {
    cout << "I=" << a << " " << "J=" << b << endl;
    b -= 5;
    a += 3;
  }
}
