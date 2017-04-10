// http://codeforces.com/contest/795/problem/K

var n = parseInt(readline());
var s = readline();

function is_vowel(c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

var ans = "";
for (var i = 0; i < n ; ) {
  if (is_vowel(s[i])) {
    var cnt = 0;
    var cur = s[i];
    var j;
    for (j = i; j < n; ++j) {
      if (s[j] != s[i]) break;
      cnt ++;
    }

    if (s[i] == 'e' || s[i] == 'o') {
      if (cnt == 2) {
        ans += cur + cur;
      }
      else {
        ans += cur;
      }
    }
    else {
      ans += cur;
    }
    i = j;
  }
  else {
     ans += s[i];
     i ++;
  }
}

print(ans)