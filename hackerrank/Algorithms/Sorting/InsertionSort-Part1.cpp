#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */
void print(vector<int> ar){
  for(int i=0;i<ar.size();i++){
    if(i>0) cout << " ";
    cout << ar[i];
  }
  cout << endl;
}

void insertionSort(vector <int>  ar) {
  int t = ar.size(),f = 0;
  int last = ar[t-1];
  if(t==1) print(ar);
  else {
    for(int i=t-2; i>=0; i--){
      if(last > ar[i]){
        ar[i+1] = last;
        print(ar);
        break;
      }
      else {
        ar[i+1] = ar[i];
        print(ar);
      }
      if(i==0 && !f) {
        ar[0] = last;
        print(ar);
        break;
      }
    }
  }
}

/* Tail starts here */
int main() {
  vector <int>  _ar;
  int _ar_size;
  cin >> _ar_size;
  for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
    int _ar_tmp;
    cin >> _ar_tmp;
    _ar.push_back(_ar_tmp);
  }

  insertionSort(_ar);

  return 0;
}
