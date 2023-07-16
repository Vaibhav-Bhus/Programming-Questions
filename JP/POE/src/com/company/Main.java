package com.company;

import java.util.*;

class Main
{
    /*
    OTP Generation
    Input Format: 13456
    Output Format:1925
    Explanation:
    Take the string of numbers and generate a four
    digit OTP such that
    1.If the number is odd square it.
    2.If the number is even ignore it.
    */


    public static void main(String args[])
    {
        Scanner sc = new Scanner (System.in);
        int digit, ans=0, ans2 = 0,flag, fg;
        System.out.print("Enter Any Numebr : ");
        int n=sc.nextInt();
        while (n!=0){
            digit = n%10;
            if (digit % 2 == 1) {
                flag = digit * digit;
                while (flag!=0){
                    fg = flag %10;
                    ans  = (ans*10) +fg;
                    flag = flag/10;
                }
            }
            n = n / 10;
        }
        while(ans!=0){
            digit = ans % 10;
            ans2  = (ans2*10) + digit;
            ans = ans/10;
        }
        System.out.println(ans2);
    }
}