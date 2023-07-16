import java.lang.*;
import java.util.Scanner;

public class Q4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num, digit, sum = 0;
        System.out.print("Enter the number : ");
        num = sc.nextInt();
        while (num / 10 != 0) {
            digit = (num % 10) * 10;
            num /= 10;
            digit = digit + (num % 10);
            sum += digit;
        }
        System.out.println("Sum of Digits : "+sum);
    }
}