package com.company;
import java.util.*;

public class TwoDSnippet
{
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int m = sc.nextInt();
        int mat[][] = new int[m][];
        sc.nextLine();
        for(int i=0;i<m;i++){
            String str[] = sc.nextLine().split(",");
            int temp[] = new int[str.length];
            for(int j=0;j<str.length;j++){
                temp[j] = Integer.parseInt(str[j]);
            }
            mat[i] = temp;
        }
        boolean leftToRight = true;

        int n = mat[0].length;
        int ans = 0;
        int output = -1;

        for(int i=0;i<m;i++){
            if(leftToRight){
                for(int j=0;j<n;j++){
                    ans += mat[i][j];
                    if(isPerfectSquare(ans)){
                        output = Math.max(output,ans);
                        ans = 0;
                    }
                }
            }else{
                for(int j=n-1;j>-1;j--){
                    ans += mat[i][j];
                    if(isPerfectSquare(ans)){
                        output = Math.max(output,ans);
                        ans = 0;
                    }
                }
            }
            leftToRight = !leftToRight;
        }

        System.out.println(output);
    }

    static boolean isPerfectSquare(int n){

        double sqrt = Math.sqrt(n*1.0);

        return (sqrt-Math.floor(sqrt))==0;

    }

}