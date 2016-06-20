// http://codeforces.com/contest/683/problem/D

import java.util.Scanner
import java.util.Arrays

data class pupil(val name: String, val height: Int)

fun main(args: Array<String>) {
  val T = Integer.parseInt(readLine())

  for (i in 1..T) {
    var line = readLine()!!.split(' ')

    var ans = false
    var n = Integer.parseInt(line[0]);
    var m = Integer.parseInt(line[1]);
    var p = Integer.parseInt(line[2]);

    for (j in 1..n) {
      for (k in 1..m) {
        if (j * k == p) {
          ans = true;
        }
      }
    }

    if (ans) println("Yes")
    else println("No")
  }
}