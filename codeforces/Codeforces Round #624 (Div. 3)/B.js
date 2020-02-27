// http://codeforces.com/contest/1311/problem/B

'use strict'

let t = parseInt(readline())
const readInts = () => readline().split(' ').map(n => parseInt(n))
const readInt = () => readInts[0]

while (t --> 0) {
  const nm = readInts()
  const arr = readInts()
  const p = readInts()

  let found = true
  while (found) {
    found = false
    for (let i in p) {
      const pos = p[i]
      if (arr[pos - 1] > arr[pos]) {
        const tmp = arr[pos - 1]
        arr[pos - 1] = arr[pos]
        arr[pos] = tmp
        found = true
      }
    }
  }

  let ok = true
  for (let i = 1; i < arr.length; ++i) {
    if (arr[i - 1] > arr[i]) {
      ok = false
      break
    }
  }
  print(ok ? 'YES' : 'NO')
}