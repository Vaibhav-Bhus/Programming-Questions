package com.company;

import java.util.Locale;

public class string_methods {
    public static void main(String []args){
        String s = "Samiksha  ";

        System.out.println("length of string:-"+s.length());
        System.out.println("lower case:- "+s.toLowerCase());
        System.out.println("upper case:-"+s.toUpperCase());
        System.out.println("trim :-"+s.trim());
        System.out.println("substring:-"+s.substring(2));
        System.out.println("substring:- "+s.substring(2,5));
        System.out.println("replace:-"+s.replace('a','x'));
        System.out.println("starts with:- "+s.startsWith("Sa"));
        System.out.println("ends with:- "+s.endsWith(" "));
        System.out.println("character at:-"+s.charAt(3));
        System.out.println("index of:-"+s.indexOf("s"));
        System.out.println("index of:- "+s.indexOf('a',3));
        System.out.println("equals:- "+s.equals("Samiksha  "));
        System.out.println("equals ignore case:- "+s.equalsIgnoreCase("samIkSha  "));

        System.out.println("code point at:- "+s.codePointAt(3));//unicode return krtai
        System.out.println("compare to:- "+s.compareTo("Samiksha  "));//kalla nai
        System.out.println("concat:- "+s.concat("purwat"));
    }

}
