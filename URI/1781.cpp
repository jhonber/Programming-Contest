#include<bits/stdc++.h>
using namespace std;
 
bool is_vowel(char x) {
  return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}
 
int main() {
  int n;
  cin >> n;
 
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
 
    int v = 0;
    int c = 0;
    int size = s.size();
    vector<int> vv, cc;
    for (int j = 0; j < size; ++j) {
      if (is_vowel(s[j])) {
        vv.push_back(j);
      }
      else {
        cc.push_back(j);
      }
    }
 
    printf("Caso #%d:\n", i + 1);
    int q;
    cin >> q;
    for (int j = 0; j < q; ++j) {
      int type, x;
      cin >> type;
      if (type == 0) {
        cin >> x;
        v += x;
      }
      else if (type == 1) {
        cin >> x;
        c += x;
      }
      else {
        int cnt1 = 0;
        int cnt2 = 0;
        vector< pair<int, char> > all(size);
        for (int k = 0; k < s.size(); ++k) {
          if (is_vowel(s[k])) {
            int pos = (cnt1 + v) % (int)vv.size();
            all[k] = {vv[pos], s[k]};
            cnt1 ++;
          }
          else {
            int pos = (cnt2 + c) % (int)cc.size();
            all[k] = {cc[pos], s[k]};
            cnt2 ++;
          }
        }
        sort(all.begin(), all.end());
        for (int k = 0; k < size; ++k) printf("%c", all[k].second);
        printf("\n");
      }
    }
  }
 
  return 0;
}
