package com.company;

import java.util.*;

public class multiplication_of_arrays {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("enter size:-");

        int size = sc.nextInt();

        int[] arr1 = new int[size];
        int[] arr2 = new int[size];
        int[] arr3 = new int[size];


        for (int i = 0; i < size; i++) {
            arr1[i] = sc.nextInt();
        }


        for (int i = 0; i < size; i++) {
            arr2[i] = sc.nextInt();
        }


        for (int i = 0; i < size; i++) {
            arr3[i] = arr1[i] * arr2[i];

        }


        for (int i = 0; i < size; i++) {
            System.out.println(arr3[i]);
        }
    }
}
