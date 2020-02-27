// http://codeforces.com/contest/1300/problem/A

'use strict'

const readInts = () => {
  return readline().split(' ').map(num => parseInt(num))
}

const readInt = () => readInts()[0]

let t = readInt()

while (t --> 0) {
  const n = readInt()
  const arr = readInts()

  let ans = 0
  let sum = 0
  for (let i in arr) sum += arr[i]

  for (let i in arr) {
    if (!arr[i]) {
      arr[i] ++
      ans ++
      sum ++
    }
  }

  if (!sum) {
    for (let i in arr) {
        if (arr[i] + 1 !== 0) {
            arr[i] ++
            ans ++
            break
        }
    }
  }

  print(ans)
}
