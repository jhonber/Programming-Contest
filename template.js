'use strict'

const io = require('./lib/io')(main)
const readline = io.readline
const print = io.print

const getLine = () => readline().split(' ')
const getInts = () => getLine().map(n => parseInt(n))
const getInt = () => readInts()[0]

// main()
const main = () => {
}
