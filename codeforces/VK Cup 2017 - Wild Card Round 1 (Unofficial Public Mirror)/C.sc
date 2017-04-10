// http://codeforces.com/contest/795/problem/C

object Main extends App {
    var ans :String = ""
    val n = readInt

    if (n % 2 == 0) {
      for (i <- 1 to n / 2) {
        print(1)
      }
    }
   else {
     print(7)
     for (i <- 1 to (n - 3) / 2) {
       print(1)
     }
   }
 
    println()

}