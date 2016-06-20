// http://codeforces.com/contest/683/problem/B

import java.util.Scanner
import java.util.Arrays

data class pupil(val name: String, val height: Int)

fun main(args: Array<String>) {
  val n = Integer.parseInt(readLine())

  val v = arrayListOf<pupil>()
  for (i in 1..n) {
    val (name, tmp) = readLine()!!.split(' ');
    val height = Integer.parseInt(tmp)
    v.add(pupil(name, height))
  }

  for (i: Int in 120..230) {
    for (j: Int in 0..v.count()-1) {
      if (v[j].height == i) {
        println(v[j].name)
      }
    }
  }
}