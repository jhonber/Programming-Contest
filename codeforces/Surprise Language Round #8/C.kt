// http://codeforces.com/contest/683/problem/C

import java.util.Scanner
import java.util.Arrays

fun main(args: Array<String>) {
  val line1 = readLine()!!.split(' ')
  val line2 = readLine()!!.split(' ')

  val set = hashSetOf<Int>();
  val set2 = hashSetOf<Int>();


  for (i: Int in 1..line1.count() - 1) {
    set.add(Integer.parseInt(line1[i]));
  }

  for (i: Int in 1..line2.count() - 1) {
    set2.add(Integer.parseInt(line2[i]));
  }

  val ans = hashSetOf<Int>();

  for (i: Int in 1..line2.count() - 1) {
    val num = Integer.parseInt(line2[i]);
    if (!set.contains(num)) {
      ans.add(num);
    }
  }

  for (i: Int in 1..line1.count() - 1) {
    val num = Integer.parseInt(line1[i]);
    if (!set2.contains(num)) {
      ans.add(num);
    }
  }

  val size = ans.size;
  print("$size");
  for (i in ans) {
    print(" $i")
  }

  println();

}