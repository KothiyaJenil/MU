import java.util.Scanner;

public class ex12 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int revers = 0;

    System.out.print("enter number : ");
    int number = sc.nextInt();

    while (number > 0) {
      int n = number % 10;
      revers = revers * 10 + n;
      number = number / 10;
    }

    System.out.println("revers number is : " + revers);

    sc.close();
  }
}
