package com.company;

import java.util.ArrayList;
import java.util.Scanner;


public class Manthan2 {
    static int len =100;
    public static void main(String[] args) {
        ArrayList<int[]> x = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        for (int i = 0; i < size; i++) {
            String[] valuesStrArr = sc.nextLine().split(",");
            int[] y = new int[valuesStrArr.length];
            len = valuesStrArr.length;
            for (int j = 0; j < len; j++) {
                y[j] = Integer.parseInt(valuesStrArr[j]);
            }
            x.add(y);
        }

    }
}
