// http://codeforces.com/contest/1311/problem/A

'use strict'

let t = parseInt(readline())

while (t --> 0) {
  const arr = readline().split(' ').map(n => parseInt(n))
  const a = arr[0]
  const b = arr[1]
  
  let ans = 0
  const diff = Math.abs(a - b)
  if (a < b) {
    if (diff % 2) ans = 1
    else ans = 2
  } else if (a > b) {
    if (diff % 2) ans = 2
    else ans = 1
  }
  print(ans)
}