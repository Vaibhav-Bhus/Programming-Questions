//package com.company;
//
//import java.util.Arrays;
//import java.util.Scanner;
//
//public class subgroups {
//    static Scanner sc = new Scanner(System.in);
//    public static void main(String[] args) {
//        String line;
//        String[] lineVector;
//        System.out.print("Enter your values ',' saparted : ");
//        line = sc.nextLine(); //read 1,2,3
//        lineVector = line.split(",");
//        int len = lineVector.length;
//        int[] arr = new int[len];
//        int[] arr1 = new int[len];
//        int[] arr2 = new int[len];
//        int[] rev = new int[len];
//
//
//        for (int i = 0; i < len; i++)
//            arr[i] = Integer.parseInt(lineVector[i]);
//
//        Arrays.sort(arr);
//        int j = 0;
//        for(int i = len;i>0 ; i--,j++)
//        {
//            rev[j] = arr[i-1];
//        }
//
//        for (int value:rev
//             ) {
//            System.out.println(value);
//        }
//        int target = Arrays.stream(rev).sum()/2;
//        System.out.println("target: "+target);
//
//        for (int i = 0; i < len; i++) {
//            if (target >= Arrays.stream(arr1).sum()+rev[i])
//                arr1[i] = rev[i];
//            else
//                arr2[i] = rev[i];
//        }
//        System.out.println("First");
//        for (int value:arr1) {
//            System.out.println(value);
//        }
//        System.out.println("Second");
//        for (int value:arr2) {
//            System.out.println(value);
//        }
//    }
//}


package com.company;

        import java.util.Scanner;
import java.lang.Integer;
// JAVA Code for Maximum size square
// sub-matrix with all 1s
public class subgroups
{
    // method for Maximum size square sub-matrix with all 1s
    static void printMaxSubSquare(int M[][])
    {
        int i,j;
        int R = M.length;		 //no of rows in M[][]
        int C = M[0].length;	 //no of columns in M[][]
        int S[][] = new int[R][C];

        int max_of_s, max_i, max_j;

        for(i = 0; i < R; i++)
            S[i][0] = M[i][0];

        for(j = 0; j < C; j++)
            S[0][j] = M[0][j];

        for(i = 1; i < R; i++)
        {
            for(j = 1; j < C; j++)
            {
                if(M[i][j] == 1)
                    S[i][j] = Math.min(S[i][j-1],
                            Math.min(S[i-1][j], S[i-1][j-1])) + 1;
                else
                    S[i][j] = 0;
            }
        }

		/* Find the maximum entry, and indexes of maximum entry
			in S[][] */
        max_of_s = S[0][0]; max_i = 0; max_j = 0;
        for(i = 0; i < R; i++)
        {
            for(j = 0; j < C; j++)
            {
                if(max_of_s < S[i][j])
                {
                    max_of_s = S[i][j];
                    max_i = i;
                    max_j = j;
                }
            }
        }
        int cnt = 0;
        for(i = max_i; i > max_i - max_of_s; i--)
        {
            for(j = max_j; j > max_j - max_of_s; j--)
            {
                cnt++;
            }
            System.out.println();
        }
        if (cnt<=1)
            System.out.println("-1");
        else
            System.out.println(cnt);
    }

    // Driver program
    public static void main(String[] args) throws NumberFormatException
    {
        Scanner sc=new Scanner(System.in);
        int row = sc.nextInt();
        int twoD[][]=new int[2][4];


        for(int i=0; i<2;i++)
        {
            for(int j=0; j<4;j++)
            {
                twoD[i][j]=sc.useDelimiter(",").nextInt();
            }
        }




//        Scanner sc = new Scanner(System.in);
//        System.out.println("enter no");
//        int n = sc.nextInt();
//        String line;
//        String[] lineVector;
//        int[][] M = new int[n][100];
//        int[] array =new int[5];
//        for (int i = 0; i < n; i++) {
//            line = sc.nextLine(); //read 1,2,3
//            lineVector = line.split(",");
//            for (int j = 0; j < lineVector.length; j++) {
//                array[i] =Integer.parseInt(lineVector[i]);
//            }
//        }
        printMaxSubSquare(twoD);
    }

}

