package com.company;

import java.util.Scanner;

public class Mitali {
    static boolean check(int mid, int array[], int n, int K)
    {

        int count = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {

            if (array[i] > mid)
                return false;
            sum += array[i];
            if (sum > mid) {
                count++;
                sum = array[i];
            }
        }
        count++;

        if (count <= K)
            return true;
        return false;
    }
    static int solve(int array[], int n, int K)
    {
        int start = 1;
        for (int i = 0; i < n; ++i) {
            if (array[i] > start)
                start = array[i];
        }
        int end = 0;

        for (int i = 0; i < n; i++) {
            end += array[i];
        }

        int answer = 0;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (check(mid, array, n, K)) {
                answer = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return answer;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String [] str = s.split(",");
        int[] array = new int[str.length];
        for (int i = 0; i < str.length; i++) {
            array[i] = Integer.parseInt(str[i]);
        }
        int k = sc.nextInt();
        System.out.println(solve(array,array.length,k));
    }
}
