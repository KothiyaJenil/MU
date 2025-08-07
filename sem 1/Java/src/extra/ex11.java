import java.util.Scanner;

public class ex11 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int sum = 0;

    System.out.print("enter length of numbers : ");
    int n = sc.nextInt();

    for (int i = 0; i < n; i++) {
      System.out.print("enter number : ");
      sum += sc.nextInt();
    }

    System.out.println("sum of the numbers  is : " + sum);

    sc.close();
  }
}