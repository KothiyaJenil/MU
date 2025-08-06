import java.util.Scanner;

public class ex3 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("enter principal amount : ");
    int principalAmount = sc.nextInt();

    System.out.print("enter rate of interest : ");
    int rate = sc.nextInt();

    System.out.print("enter number of year : ");
    int year = sc.nextInt();

    double simpleInterest = (principalAmount * rate * year) / 100;
    System.out.println("Simple interest is : " + simpleInterest);

    sc.close();
  }
}
