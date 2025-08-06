import java.util.Scanner;

public class ex5 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("enter first subject mark : ");
    int subMark1 = sc.nextInt();
    System.out.print("enter second subject mark : ");
    int subMark2 = sc.nextInt();
    System.out.print("enter third subject mark : ");
    int subMark3 = sc.nextInt();

    int total = subMark1 + subMark2 + subMark3;
    double per = (total * 100) / 300;
    if (per < 95) {
      System.out.println("your grad is A and your per is " + per);
    }
    else if (per < 80) {
      System.out.println("your grad is B and your per is " + per);
    }
    else if (per < 60) {
      System.out.println("your grad is C and your per is " + per);
    }
    else if (per < 45) {
      System.out.println("your grad is D and your per is " + per);
    }
    else if (per > 30) {
      System.out.println("you are fail and your per is " + per);
    }
    sc.close();
  }
}
