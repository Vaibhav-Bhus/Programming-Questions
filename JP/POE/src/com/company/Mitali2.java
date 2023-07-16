package com.company;

import java.util.ArrayList;
import java.util.Scanner;

public class Mitali2 {
    public static void main(String[] args) {
        int digit = 0;
        ArrayList<String> ar1 = new ArrayList<>();
        ArrayList<String> ar2 = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        String instr3 = sc.nextLine();
        String[] arr1 = instr3.split(",");
        String instr2 = sc.nextLine();
        String[] arr_ = instr2.split(",");
        int[] arr2 = new int[arr_.length];
        for (int i = 0; i < arr_.length; i++) {
            arr2[i] = Integer.parseInt(arr_[i]);
        }
        for (int k = 0; k < arr1.length; k++) {
            String instr = arr1[k];
            for (int i = 0; i < instr.length(); i++) {
                digit = 0;
                if (instr.charAt(i) >= 48 && instr.charAt(i) <= 57) {
                    digit = Integer.parseInt(String.valueOf(instr.charAt(i)));
                    for (int j = i + 1; j < instr.length(); j++) {
                        if (instr.charAt(j) >= '0' && instr.charAt(j) <= '9') {
                            digit = (digit * 10) + Integer.parseInt(String.valueOf(instr.charAt(j)));
                            i++;
                        }

                    }
                    if (digit != 0 && check(digit, arr2)) {
                        ar1.add(Integer.toString(digit));
                        ar2.add(instr.replaceAll("[0-9]", ""));
                    } else {
                        ar1.add("NA");
                        ar2.add("NA");
                    }

                }


            }
        }
        for (String s:ar1
             ) {
            System.out.print(s+",");
        }
        for (String s:ar2
        ) {
            System.out.print(s+",");
        }
        System.out.println(ar1);
        System.out.println(ar2);


    }
    static boolean check ( int digit, int[] array){
        for (int i = 0; i < array.length; i++) {
            if (array[i] == digit)
                return true;
        }
        return false;
    }
}
