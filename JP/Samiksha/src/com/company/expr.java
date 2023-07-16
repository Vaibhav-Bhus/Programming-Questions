package com.company;

import java.util.Scanner;

public class expr {
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);
        float v,u,a,s;
        System.out.println("Enter value of v,u,a,s:- ");
        v = sc.nextInt();
        u =  sc.nextInt();
        a =  sc.nextInt();
        s =  sc.nextInt();

        float val = ((v*v)-(u*u))/(2*a*s);
        System.out.println(val);

    }
}
