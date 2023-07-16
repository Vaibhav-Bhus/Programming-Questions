package com.company;

import java.util.*;
public class MaximumSubarraySum {
    public static void main(String[] args) {
        long[] arr;
        long[] arr1;
        long m;
        int n = 0;
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for (int a0 = 0; a0 < q; a0++)
            n = in.nextInt();
            m = in.nextLong();
            arr = new long[n];
            arr1 = new long[n];

            for (int i = 0; i < n; i++) {
                arr[i] = in.nextLong();
            }
//
            for (int i = 0; i < n; i++) {
                 long sum = 0;
                for (int j = 0; j < i; j++) {
                    sum += arr[i];
                }
                arr1[i] = sum%m;
            }
            long max = 0L;
        for (long e:arr1
             ) {max = e;
            
        }

            System.out.println(max);
            in.close();
        }

}
