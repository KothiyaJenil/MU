import java.util.Scanner;

public class ex10 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int[] arr = new int[10];

    System.out.println("enter 10 value of an array : ");
    for (int i = 0; i < 10; i++) {
      System.out.print("enter " + (i + 1) + " value : ");
      arr[i] = sc.nextInt();
    }

    System.out.println();

    for (int i = 0; i < 10; i++) {
      System.out.println((i + 1) + " of value of array is : " + arr[i]);
    }

    sc.close();
  }
}
