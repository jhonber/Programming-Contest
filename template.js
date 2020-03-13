'use strict'

const io = require('./lib/io')(main)
const readline = io.readline
const print = io.print

const getLine = () => readline().split(' ')
const getInts = () => getLine().map(n => parseInt(n))
const getInt = () => getInts()[0]
const D = (...args) => { // D({name})
  [...args].forEach(cur => print.apply(print, [JSON.stringify(cur)]))
}

// main()
function main () {
}
