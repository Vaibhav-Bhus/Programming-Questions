package com.company;
import java.util.*;
public class sum_of_naturals_no {
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        int n,sum=0,i=1;
        System.out.println("Enter num:-");
        n = sc.nextInt();

        while (i<=n)
        {
            sum = sum+i;
            i++;

        }
        System.out.println(sum);
    }
}
