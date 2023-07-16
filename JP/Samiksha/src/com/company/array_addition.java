package com.company;
import java.util.*;

public class array_addition {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] arr1 = new int[3];
        int[] arr2 = new int[3];
        int[] arr3 = new int[3];


        System.out.println("Enter 1st array elements: ");
        for (int i = 0; i < 3; i++) {
            arr1[i] = sc.nextInt();
        }

//        for (int i = 0; i < 3; i++) {
//            System.out.println(arr1);
//        }
        System.out.println("Enter 2nd array elements: ");
        for (int i = 0; i < 3; i++) {
            arr2[i] = sc.nextInt();
        }

//        for (int i = 0; i < 3; i++) {
//            System.out.println(arr2);
//
//        }
        System.out.println("Enter 3rd array elements: ");
        for (int i = 0; i < 3; i++) {
            arr3[i] = sc.nextInt();
        }

//        for (int i = 0; i < 3; i++) {
//            System.out.println(arr3[i]);
//
//        }

        int[] arr4 = new int[3];

        for (int i = 0; i < 3; i++) {
            arr4[i] = arr1[i] + arr2[i] + arr3[i];
            System.out.print(arr4[i]+" ");
        }
    }
}
