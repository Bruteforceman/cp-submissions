import java.util.*;
import java.io.*;

public class IntegerGame {
  static Scanner in;
  static Pair [] a = new Pair [3];

  static int query(long value) {
    System.out.println(value);
    System.out.flush();
    int index = in.nextInt() - 1;
    if(index < 0) {
      System.exit(0);
    }
    for(int i = 0; i < a.length; i++) {
      if(a[i].index == index) {
        a[i].value += value;
      }
    }
    Arrays.sort(a, new Pair());
    return index;
  }
  public static void main(String [] args) {
    in = new Scanner(System.in);
    for(int i = 0; i < a.length; i++) {
      a[i] = new Pair();
      a[i].value = (int) in.nextInt();
      a[i].index = i;
    }
    Arrays.sort(a, new Pair());
    System.out.println("First");
    System.out.flush();
    int index = query(2 * a[2].value - a[1].value - a[0].value);
    if(a[1].value - a[0].value == a[2].value - a[1].value) {
      index = query(a[1].value - a[0].value);
    } else {
      index = query(2 * a[2].value - a[1].value - a[0].value);
      index = query(a[1].value - a[0].value);
    }
  }
}
class Pair implements Comparator <Pair> {
  long value;
  int index;
  Pair () {}
  public int compare(Pair a, Pair b) {
    return Long.compare(a.value, b.value);
  }
}
