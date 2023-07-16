package com.company;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class CircularTracks {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String str = sc.next();
        char[] s = str.toCharArray();
        int q = sc.nextInt();
        int ans = 0;
        while (q--!=0){
            int n1 = sc.nextInt();
            if (n1==1)
                ans+=n;
            else{
                for (int i = 0; i < n-n1; i++) {
                   ArrayList<Character> check = new ArrayList<>();
                    for (int j = 0; j < n1; j++) {
                        check.add(s[i+j]);
                    }
                    String str1 = getStringRepresentation(check);
                    Collections.reverse(check);
                    String str2 = getStringRepresentation(check);
                    if (str1.compareTo(str2)==0)
                        ans+=1;
                }
            }
        }
        System.out.println(ans+1);
    }
    static String getStringRepresentation(ArrayList<Character> list)
    {
        StringBuilder builder = new StringBuilder(list.size());
        for(Character ch: list)
        {
            builder.append(ch);
        }
        return builder.toString();
    }
}
