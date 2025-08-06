public class ex10_8 {
  public static void main(String[] args) {
    float sum = 0;
    for (int i = 1; i < 10; i++) {
      sum += (float) i / (i + 1);
    }
    System.out.print("sum : " + sum);
  }
}
