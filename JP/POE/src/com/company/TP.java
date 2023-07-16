package com.company;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
//import java.util.*;

public class TP {
//    public static void main(String[] args) {
//        Scanner sc = new Scanner(System.in);
//        String s = sc.nextLine();
//        String [] str = s.split(",");
//        int[] array = new int[str.length];
//        for (int i = 0; i < str.length; i++) {
//            array[i] = Integer.parseInt(str[i]);
//        }
//
//    }

//    public static void main(String[] args)
//    {
//        Scanner s = new Scanner(System.in);
//        int size = Integer.parseInt(s.nextLine());
//        int[][] tablero = new int[size][size];
//        boolean exit = false;
//        while (!exit) {
//            for (int i = 0; i < size; i++) {
//                String valuesStrArr[] = s.nextLine().split(",");
//                for (int j = 0; j < valuesStrArr.length; j++) {
//                    tablero[i][j] = Integer.parseInt(valuesStrArr[j]);
//                }
//                if (i == size - 1)
//                    exit = true;
//            }
//        }
//        for (int i = 0; i < size; i++) {
//            for (int j = 0; j < size; j++) {
//                System.out.print(tablero[i][j]+"  ");
//            }
//            System.out.println();
//        }
//    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in).useDelimiter(",");
        int n = 2;
        ArrayList<Integer>[] al = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            al[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < n; i++) {
            String valuesStrArr = sc.nextLine();
            String[] str = valuesStrArr.split("[,]");
            for (int j = 0; j < str.length; j++) {
                al[i].add(Integer.parseInt(str[j]));
            }
        }

        for (int i = 0; i < n; i++) {
            if (i%2==0){
                for (int j = 0; j < al[i].size(); j++) {

                }
            }
            else{
                for (int j = al[i].size(); j >=0 ; j--) {

                }
            }
        }


//
//        for (int i = 0; i < n; i++) {
//
//            for (int j = 0; j < al[i].size(); j++) {
//                System.out.print(al[i].get(j));
//            }
//            System.out.println("");
//        }
    }






//        ArrayList<ArrayList<Integer>> x = new ArrayList<ArrayList<Integer> >();
//        Scanner sc = new Scanner(System.in);
//        int size = sc.nextInt();
//        for (int i = 0; i < size; i++) {
//            String valuesStrArr[] = sc.nextLine().split(",");
//            int[] y = new int[valuesStrArr.length];
//            for (int j = 0; j < valuesStrArr.length; j++) {
//                y[j] = Integer.parseInt(valuesStrArr[j]);
//            }
//            x.add(new ArrayList<Integer>(Arrays.asList(y)));
//        }
//        x.add(new ArrayList<Integer>(Arrays.asList(3, 4, 6,4)));
//        x.add(new ArrayList<Integer>(Arrays.asList(2, 3, 1,6)));
//        System.out.println(x);
    }

