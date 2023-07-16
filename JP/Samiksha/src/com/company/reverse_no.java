package com.company;
import java.util.*;
import java.util.Scanner;

public class reverse_no {
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        int a,digit;
        System.out.println("enter number:-" );
        a = sc.nextInt();
        int ans=0;
        while (a!=0)
        {
            digit = a%10;

            ans = (ans*10)+digit;
            a = a/10;
            System.out.println(a);
        }

        System.out.println("ans is:-"+ans);
    }
}
