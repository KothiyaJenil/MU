import java.util.Scanner;

public class ex6 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("enter your name : ");
    String name = sc.nextLine();

    for (int i = 0; i < 10; i++) {
      System.out.println("name is " + name);
    }

    sc.close();
  }
}
