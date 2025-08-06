import java.util.Scanner;

public class ex10_6 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("enter a number : ");
    int number = sc.nextInt();
    int first = 0, second = 1;

    for (int i = 0; i < number; i++) {
      System.out.print(first + " ");
      int next = first + second;
      first = second;
      second = next;
    }

    sc.close();

  }
}

// 0 + 1