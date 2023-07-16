package com.company;

import java.util.Scanner;

public class Homeless {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter Number of House : ");
        int n = sc.nextInt();
        int[] people = new int[n];
        int[] house = new int[n];
        int cnt = 0;
        System.out.println("Enter people array:");
        for (int i = 0; i < n; i++)
            people[i] = sc.nextInt();

        System.out.println("Enter House array : ");
        for (int i = 0; i < n; i++)
            house[i] = sc.nextInt();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(house[j] > people[i]){
                    cnt+=1 ;
                    house[j]=-1;
                    break ;
                }
            }
        }
        System.out.println("Total Homeless peoples : "+(n-cnt));
    }
}
