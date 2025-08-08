import java.util.Scanner;

public class ex2 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("enter your name : ");
    String name = sc.nextLine();

    System.out.println("your name is " + name);

    sc.close();
  }
}
