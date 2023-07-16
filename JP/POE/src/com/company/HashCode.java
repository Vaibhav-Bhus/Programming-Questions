package com.company;
import java.util.HashMap;
import java.util.Scanner;
class Contributors {
    Scanner sc = new Scanner(System.in);
    HashMap<String, String> hmap = new HashMap<>();
    String[]  arr =new String[2];
    Contributors(){
            this.arr = sc.nextLine().split(" ");
            int skill = Integer.parseInt(arr[1]);
            for (int j = 0; j < skill; j++) {
                String[]  arr1 = sc.nextLine().split(" ");
                hmap.put(arr1[0],arr1[1]);
            }
        }
}
class Projects {
    Scanner sc = new Scanner(System.in);
    HashMap<String, String> hmap = new HashMap<>();
    String[]  arr = new String[2];
    Projects(){
        arr = sc.nextLine().split(" ");
        int skill = Integer.parseInt(arr[1]);
        for (int j = 0; j < skill; j++) {
            String[]  arr1 = sc.nextLine().split(" ");
            hmap.put(arr1[0],arr1[1]);
        }
    }
}
public class HashCode {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[]  f = sc.nextLine().split(" ");
        int first = Integer.valueOf(f[0]);
        int second = Integer.valueOf(f[1]);
        System.out.println(first);
        System.out.println(second);
        Contributors[] con = new Contributors[first];
        Projects[] pro = new Projects[second];
        for (int i = 0; i < first; i++)
            con[i] = new Contributors();
        for (int j = 0; j < second; j++)
            pro[j] = new Projects();
        System.out.println(first+" Contributors, "+second+" Projects");
        for (int i = 0; i < first; i++) {
            System.out.println("contributor "+con[i].arr[0]);
            con[i].hmap.forEach((key, value) -> System.out.println("has "+ key + " skill at level " + value));
        }
        for (int i = 0; i < second; i++) {
            System.out.println("Project "+pro[i].arr[0]+" needs "+pro[i].arr[1] +" contributor");
            pro[i].hmap.forEach((key, value) -> System.out.println("that needs to have " +key+ " at level ≥ "+value));
        }
    }
}
