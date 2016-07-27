#include <bits/stdc++.h>
using namespace std;

// Begin my code
void printKMax(int v[], int n, int k){
  map<int, int> get_max;
  deque<int> Q;

  for (int i = 0; i < k; ++i) {
    Q.push_back(v[i]);
    get_max[v[i]] ++;
  }

  vector<int> ans;
  ans.push_back((*get_max.rbegin()).first);

  int ind = 0;
  for (int i = k; i < n; ++i, ++ind) {
    int deleted = v[ind];
    int added = v[i];

    Q.pop_front();
    Q.push_back(added);

    get_max[added] ++;
    get_max[deleted] --;

    if (get_max[deleted] == 0) get_max.erase(deleted);

    ans.push_back((*get_max.rbegin()).first);
  }

  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " "; cout << endl;
}
//end my code

int main(){

  int t;
  cin >> t;
  while(t>0) {
    int n,k;
    cin >> n >> k;
    int i;
    int arr[n];
    for(i=0;i<n;i++)
      cin >> arr[i];
    printKMax(arr, n, k);
    t--;
  }
  return 0;
}
