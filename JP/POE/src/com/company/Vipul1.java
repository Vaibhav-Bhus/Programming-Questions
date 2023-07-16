package com.company;
import java.util.*;

class Vipul1{
    static ArrayList<String> arr = new ArrayList<>();
    static void printSubStrings(String str)
    {

        for (int i = 0; i < str.length(); i++) {
            String subStr="";

            for (int j = i; j < str.length(); j++) {
                if (subStr.contains("1") && (str.charAt(j)=='1'))
                    break;
                else
                    subStr+=str.charAt(j);
                System.out.print(subStr +"\n");
            }
        }
    }

    // Driver Code
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String instr = sc.nextLine();
        String str = "101001";
        printSubStrings(str);
    }
}

// This code is contributed by gauravrajput1