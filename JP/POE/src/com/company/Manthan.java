package com.company;

import java.util.ArrayList;
import java.util.Scanner;

public class Manthan {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        ArrayList<Integer> arr = new ArrayList<>();
        String instr = s.nextLine();
        int outnum = 0, sum = 0, digit=0,rev=0;
        for (int i = 0; i < instr.length(); i++) {
            digit = 0;
            if (instr.charAt(i) >= 48 && instr.charAt(i) <= 57) {
                digit = Integer.parseInt(String.valueOf(instr.charAt(i)));
                for (int j = i+1; j < instr.length(); j++) {
                    if (instr.charAt(j) >= '0' && instr.charAt(j) <= '9') {
                        digit = (digit * 10) + Integer.parseInt(String.valueOf(instr.charAt(j)));
                        i++;
                    } else{

                        break;
                    }
                }
            }
            if (digit!=0)
                arr.add(digit);
        }
        digit = 0;
        for (int i: arr) {
            outnum = outnum+(i%10);
        }
        boolean is = isPrime(outnum);
        if (is){
            System.out.println(outnum);
            return;
        }

        else{
            while(outnum != 0) {
                digit = outnum % 10;
                rev = rev * 10 + digit;
                outnum /= 10;
            }
        }
        boolean is2 = isPrime(rev);
        if (is2){
            System.out.println(rev);
            return;
        }
        outnum=0;
        for (int i = 1; i <= rev; ++i) {

            if (rev % i == 0) {
                outnum++;
            }
        }
        if (outnum!=0)
            System.out.println(outnum);
        else
            System.out.println("-1");
    }

    static boolean isPrime(int n){
        if (n<=1)
            return false;
        for (int i = 2; i < n; i++) {
            if (n%i==0){
                return false;
            }
        }
        return true;
    }
}
