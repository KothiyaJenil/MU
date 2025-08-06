import java.util.Scanner;

public class ex9 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int max = Integer.MIN_VALUE;
    System.out.println(max);

    System.out.println("Enter 10 numbers:");

    for (int i = 1; i <= 10; i++) {
      System.out.print("Enter number " + i + ": ");
      int num = sc.nextInt();

      if (num > max) {
        max = num;
      }
    }

    System.out.println("Maximum number is: " + max);
    sc.close();
  }
}
