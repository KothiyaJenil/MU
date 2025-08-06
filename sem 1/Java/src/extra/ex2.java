import java.util.Scanner;

public class ex2 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("enter first number : ");
    int num1 = sc.nextInt();

    System.out.print("enter second number : ");
    int num2 = sc.nextInt();

    System.out.println("addition of tow number is : " + (num1 + num2));
    System.out.println("subtraction of tow number is : " + (num1 - num2));
    System.out.println("multiplication of tow number is : " + (num1 * num2));
    System.out.println("division of tow number is : " + (num1 / num2));
    System.out.println("modulo of tow number is : " + (num1 % num2));

    sc.close();

  }
}
