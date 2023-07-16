package com.company;
import java.util.*;

public class percentage_of_students {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int a,b,c,d,e;
        System.out.println("enter 5 sub marks:-");
        a= sc.nextInt();
        b= sc.nextInt();
        c= sc.nextInt();
        d= sc.nextInt();
        e= sc.nextInt();

        int total = a+b+c+d+e;
        System.out.println("total is:-"+total);

        float per = (float)total/50*100;
        System.out.println("percntage is:-"+per);
    }














}
