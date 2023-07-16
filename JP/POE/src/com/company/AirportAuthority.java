package com.company;

import java.util.Scanner;

public class AirportAuthority {
    public static String Snake(String str, int numRows){
        if (numRows==1)
            return str;
        StringBuilder ret = new StringBuilder();
        int n = str.length();
        int cyclelen = 2*numRows-2;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j+i < n; j+=cyclelen) {
                ret.append(str.charAt(j+i));
                if (i!=0&&i!=numRows-1&&j+cyclelen-i<n)
                    ret.append(str.charAt(j+cyclelen-i));
            }
        }
        return ret.toString();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        String str = sc.nextLine();
        int rows = sc.nextInt();
        System.out.println(Snake(str,rows));

    }
}

