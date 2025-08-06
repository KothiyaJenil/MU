import java.util.Scanner;

public class ex8 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int[] numbers = new int[10];
    int sum = 0;
    System.out.println("enter 10 numbers : ");
    for (int i = 0; i < 10; i++) {
      numbers[i] = sc.nextInt();
      sum += numbers[i];
    }

    System.out.println("sum of 10 numbers is : " + sum);

    double avg = (double) sum / numbers.length;
    System.out.println("average of 10 numbers is : " + avg);

    sc.close();
  }
}
