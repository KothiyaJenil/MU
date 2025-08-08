import java.util.Scanner;

public class ex3 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("enter your name : ");
    String name = sc.nextLine();
    System.out.print("enter your DOB : ");
    String DOB = sc.nextLine();
    System.out.print("enter your enrollment : ");
    Long enrNo = sc.nextLong();
    System.out.print("enter your GR no. : ");
    Long grNo = sc.nextLong();
    sc.nextLine();
    System.out.print("enter your department : ");
    String dept = sc.nextLine();

    System.out.println("\nyour name : " + name);
    System.out.println("your DOB : " + DOB);
    System.out.println("your enrollment no : " + enrNo);
    System.out.println("your GR no : " + grNo);
    System.out.println("your department : " + dept);

    sc.close();
  }
}
