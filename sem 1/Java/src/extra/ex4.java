import java.util.Scanner;

public class ex4 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    double dollarPrice = 81.10;

    System.out.print("enter ₹ : ");
    double rs = sc.nextDouble();

    double convert = rs / dollarPrice;

    System.out.println("₹ to $ : " + convert);

    sc.close();
  }
}