import java.io.*;
import java.util.*;
public class Anti {
  public static void main(String [] args) {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt();
    for(int cs = 1; cs <= t; cs++) {
      char s[][] = new char [9][9];
      for(int i = 0; i < 9; i++) {
        s[i] = in.next().toCharArray();
      }
      for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
          if(s[i][j] == '1') s[i][j] = '2';
        }
        System.out.println(s[i]);
      }
    }
  }
}
