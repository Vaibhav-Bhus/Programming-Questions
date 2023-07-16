import java.lang.*;
import java.util.Scanner;
public class Q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num1, num2, sum = 0;
        System.out.print("Enter the 1st number : ");
        num1 = sc.nextInt();
        System.out.print("Enter the 2nd number : ");
        num2 = sc.nextInt();
        while (num1 > 0 && num2 > 0) {
            sum += ((num1 % 10) * (num2 % 10));
            num1 /= 10;
            num2 /= 10;
        }
        System.out.println("Sum of Digits : "+sum);

    }
}
