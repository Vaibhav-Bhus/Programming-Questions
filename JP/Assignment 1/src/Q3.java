import java.lang.*;
import java.util.Scanner;


public class Q3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num, sum = 0;
        System.out.print("Enter the number : ");
        num = sc.nextInt();
        while (num / 10 != 0) {
            sum += num % 100;
            num /= 10;
        }
        System.out.println("Sum of Digits : "+sum);
    }
}