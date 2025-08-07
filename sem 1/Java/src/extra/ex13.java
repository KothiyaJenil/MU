import java.util.Scanner;

public class ex13 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int temp = 0;

    System.out.print("enter number : ");
    int number = sc.nextInt();
    int armstrong = number;

    while (number > 0) {
      int n = number % 10;
      temp += n * n * n;
      number = number / 10;
    }

    if (armstrong == temp) {
      System.out.println(armstrong + " is armstrong");
    } else {
      System.out.println(armstrong + " is not armstrong");
    }

    sc.close();
  }
}
