import java.util.Scanner;

public class ex7 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("enter first number : ");
    int num1 = sc.nextInt();
    System.out.print("enter second number : ");
    int num2 = sc.nextInt();
    System.out.print("enter third number : ");
    int num3 = sc.nextInt();

    if (num1 > num2) {
      System.out.println("number 1 is maximum");
    } else if (num2 > num3) {
      System.out.println("number 2 is maximum");
    } else {
      System.out.println("number 3 is maximum");
    }

    sc.close();
  }
}
