// http://codeforces.com/contest/683/problem/A

import java.util.Scanner
import java.util.Arrays

fun main(args: Array<String>) {
  val (a, x, y) = readLine()!!.split(' ').map(String::toInt)
  if (x > a || y > a || x < 0 || y < 0) {
    println(2)
  }
  else if (x == a || y == a || x == 0 || y == 0) {
    println(1)
  }
  else {
    println(0)
  }
}