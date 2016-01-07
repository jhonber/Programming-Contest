#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NUll);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  vector<string> all = {"i","ii","iii","iv","v","vi","vii","viii","ix","x","xi","xii","xiii","xiv","xv","xvi","xvii","xviii","xix","xx","xxi","xxii","xxiii","xxiv","xxv","xxvi","xxvii","xxviii","xxix","xxx","xxxi","xxxii","xxxiii","xxxiv","xxxv","xxxvi","xxxvii","xxxviii","xxxix","xl","xli","xlii","xliii","xliv","xlv","xlvi","xlvii","xlviii","xlix","l","li","lii","liii","liv","lv","lvi","lvii","lviii","lix","lx","lxi","lxii","lxiii","lxiv","lxv","lxvi","lxvii","lxviii","lxix","lxx","lxxi","lxxii","lxxiii","lxxiv","lxxv","lxxvi","lxxvii","lxxviii","lxxix","lxxx","lxxxi","lxxxii","lxxxiii","lxxxiv","lxxxv","lxxxvi","lxxxvii","lxxxviii","lxxxix","xc","xci","xcii","xciii","xciv","xcv","xcvi","xcvii","xcviii","xcix","c"};

  int n;
  while (true) {
  cin >> n;
  if (!n) break;

  map<char, int> count;

  for (int i = 0; i < n; ++i) {
    string s = all[i];
    for (int j = 0; j < s.size(); ++j) count[s[j]] ++;
  }

  string s = "ivxlc";
  cout << n << ": ";
  for (int i = 0; i < s.size(); ++i) {
    cout << count[s[i]] << " " << s[i];
    if (i + 1 < s.size()) cout << ", ";
  }
  cout << endl;
  }
  return 0;
}
