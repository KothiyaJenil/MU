import java.util.Scanner;

public class ex5 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("enter String value : ");
    String strVal = sc.nextLine();

    System.out.print("enter int value : ");
    int intVal = sc.nextInt();

    System.out.print("enter float value : ");
    float floatVal = sc.nextFloat();

    System.out.print("enter double value : ");
    double doubleVal = sc.nextDouble();

    System.out.print("enter boolean value : ");
    boolean boolVal = sc.nextBoolean();

    System.out.print("enter short value : ");
    short nextCharVal = sc.nextShort();

    sc.close();
  }
}
