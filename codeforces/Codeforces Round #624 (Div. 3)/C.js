// http://codeforces.com/contest/1311/problem/C

'use strict'

const getLine = () => readline().split(' ')
const getInts = () => getLine().map(n => parseInt(n))
const getInt = () => getInts()[0]

main()

function main () {
  let t = getInt()
  while (t --> 0) {
    const params = getInts()
    const s = getLine()[0]
    const mistakes = getInts()
    solve(...params, s, mistakes)
  }
}

function solve (n, m, s, mistakes) {
  const freq = Array(n + 1).fill(0)
  const ans = Array(26).fill(0)
  let accumulate = 0

  mistakes.push(n)

  for (const i of mistakes) {
    freq[0] ++
    freq[i] --
  }

  for (let i = 0; i < n; ++i) {
    const ind = s[i].charCodeAt() - 'a'.charCodeAt()
    accumulate += freq[i]
    ans[ind] += accumulate
  }

  print(ans.join(' '))
}