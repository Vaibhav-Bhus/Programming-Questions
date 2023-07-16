package com.company;
import java.util.*;

public class km_to_mile {
    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter km:- ");
        int km=sc.nextInt();
        float km_to_miles = km * 0.621371f;
        System.out.println("km to miles is:- "+km_to_miles);
    }
}
