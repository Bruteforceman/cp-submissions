import java.util.*;
import java.io.*;

public class Duck {
  public static void main(String [] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    long [][] a = new long [n][n];
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        a[i][j] = (i % 2 == 0) ? (1L << (i + j)) : 0;
        System.out.printf("%d ", a[i][j]);
      }
      System.out.println();
    }
    int q = in.nextInt();
    for(int cs = 0; cs < q; cs++) {
      long k = in.nextLong();
      int x = 0, y = 0;
      System.out.println((x + 1) + " " + (y + 1));
      for(int i = 2; i <= 2 * n - 1; i++) {
        int bit = (int) ((k >> (x + y + 1)) & 1);
        if(x == n - 1) {
          y += 1;
        } else if (y == n - 1) {
          x += 1;
        } else if (bit == 1) {
           if(a[x + 1][y] > 0) x += 1;
           else y += 1;
        } else {
          if(a[x + 1][y] > 0) y += 1;
          else x += 1;
        }
        System.out.println((x + 1) + " " + (y + 1));
      }
    }
  }
}

