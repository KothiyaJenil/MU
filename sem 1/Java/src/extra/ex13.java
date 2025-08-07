import java.util.Scanner;

public class ex13 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int revers = 0;

    System.out.print("enter number : ");
    int number = sc.nextInt();
    int palindrome = number;

    while (number > 0) {
      int n = number % 10;
      revers = revers * 10 + n;
      number = number / 10;
    }

    if (palindrome == revers) {
      System.out.println(palindrome + " is palindrome");
    } else {
      System.out.println(palindrome + " is not palindrome");
    }

    sc.close();
  }
}
