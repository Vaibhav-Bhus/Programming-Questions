package com.company;

import java.util.Scanner;

public class palindrome {
    /*
    Problem Statement-: For a given positive number num, identify the palindrome formed by performing the following operations-

Add num and its reverse
Check whether the sum is palindrome or not. If not, add the sum and its reverse and repeat the process until a palindrome is obtained
For example:

If original integer is 195, we get 9,339 as the resulting palindrome after the fourth addition:

   195

+ 591

————–

   786

+ 687

————–

   1473

+ 3741

————–

   5214

+ 4125

———-

  9339

Input format:

Read num from the standard input stream.
Output format:

Print the palindrome calculated to the standard output stream.
Sample Test Cases

Sample Input 1
124
Sample Output 1
545
Explanation 1
The sum of 124 and its reverse 421 is 545 which is a palindrome.
Sample input 1
4
Sample output 1
8
Explanation 1
The sum of 4 and its reverse 4 is 8 which is a palindrome.
    */
    static int rev(int number) {
        int ans = 0;
        while (number != 0) {
            int digit = number % 10;
            ans = ans * 10 + digit;
            number = number / 10;
        }
        return ans;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num1 = scanner.nextInt();
        while (true) {
            int num2 = num1 + rev(num1);
            if (num2 == rev(num2)) {
                System.out.println(num2);
                break;
            }
            num1 = num2;
        }
    }



}
