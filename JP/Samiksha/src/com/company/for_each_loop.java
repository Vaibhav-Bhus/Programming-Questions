package com.company;

import java.util.Scanner;

public class for_each_loop
{
    public static void main(String [] args){

        Scanner sc = new Scanner(System.in);

        System.out.println("enter size of array:- ");
        int size = sc.nextInt();

        int[] arr1 = new int[size];

        for(int i=0;i<size; i++)
        {
            arr1[i] = sc.nextInt();
        }

        for(int x: arr1)
        {
            System.out.println(x);
        }
    }

}

