package com.company;

import java.util.Scanner;

// JAVA Code for Maximum size square
// sub-matrix with all 1s
public class MeatBall
{
    // method for Maximum size square sub-matrix with all 1s
//    static void printMaxSubSquare(int M[][])
//    {
//        int i,j;
//        int R = M.length;		 //no of rows in M[][]
//        int C = M[0].length;	 //no of columns in M[][]
//        int S[][] = new int[R][C];
//
//        int max_of_s, max_i, max_j;
//
//        /* Set first column of S[][]*/
//        for(i = 0; i < R; i++)
//            S[i][0] = M[i][0];
//
//        /* Set first row of S[][]*/
//        for(j = 0; j < C; j++)
//            S[0][j] = M[0][j];
//
//        /* Construct other entries of S[][]*/
//        for(i = 1; i < R; i++)
//        {
//            for(j = 1; j < C; j++)
//            {
//                if(M[i][j] == 1)
//                    S[i][j] = Math.min(S[i][j-1],
//                            Math.min(S[i-1][j], S[i-1][j-1])) + 1;
//                else
//                    S[i][j] = 0;
//            }
//        }
//
//		/* Find the maximum entry, and indexes of maximum entry
//			in S[][] */
//        max_of_s = S[0][0]; max_i = 0; max_j = 0;
//        for(i = 0; i < R; i++)
//        {
//            for(j = 0; j < C; j++)
//            {
//                if(max_of_s < S[i][j])
//                {
//                    max_of_s = S[i][j];
//                    max_i = i;
//                    max_j = j;
//                }
//            }
//        }
//        int cnt = 0;
//        for(i = max_i; i > max_i - max_of_s; i--)
//        {
//            for(j = max_j; j > max_j - max_of_s; j--)
//            {
//                cnt++;
//            }
//            System.out.println();
//        }
//        if (cnt<=1)
//            System.out.println("-1");
//        else
//            System.out.println(cnt);
//    }

    // Driver program
    public static void main(String[] args) throws NumberFormatException
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter no");
        int n = sc.nextInt();


        int[][] M = new int[n][n];


        try {
            for(int i = 0; i < n; i++)
            {


            }
        }
        catch(Exception e){


        }
        for(int i = 0; i < n; i++)
        {

            String line = sc.nextLine();
            String[] lineVector = line.split(",");
            int k;
            try {
                k = Integer.parseInt(lineVector[0]);
            }
            catch(Exception e){
            System.out.println("number format");
        }
//            System.out.println(k);
//            Integer.parseInt(lineVector[i]);
            int len = lineVector.length;
//            for (int j = 0; j < len; j++) {
//                M[i][j] = Integer.parseInt(lineVector[i]);
//            }

//            if (i == n-1){
//                break;
//            }
//            else
//            line = sc.nextLine();
//            lineVector = line.split(",");
//            System.out.println();
        }
//        printMaxSubSquare(M);
    }

}