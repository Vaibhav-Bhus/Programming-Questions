package com.company;

import java.util.Arrays;
import java.util.Scanner;

public class GreedyFlorist {

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter N and K: ");
        String[] str1 = scanner.nextLine().split(" ");
        int n = Integer.parseInt(str1[0]);
        int k = Integer.parseInt(str1[1]);

        int[] c = new int[n];
        System.out.print("Enter C array: ");
        String[] str2 = scanner.nextLine().split(" ");
        int ans = 0, count = 1, flag = k;
        for (int i = 0; i < n; i++)
            c[i] = Integer.parseInt(str2[i]);

        Arrays.stream(c).sorted();

        for (int i = c.length-1; i >=0; i--) {
            if (flag==0) {
                flag=k;
                count++;
            }
            ans+=c[i]*count;
            flag--;
        }
        System.out.print("Final ans: ");
        System.out.println(ans);
    }
}
