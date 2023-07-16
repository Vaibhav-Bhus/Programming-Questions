package com.company;
import java.util.*;
import java.lang.*;

class Codechef
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc= new Scanner(System.in);
        int t=sc.nextInt();

        for(int i=1;i<=t;i++)
        {
            int a=sc.nextInt();
            int b=sc.nextInt();

            float f=(float)(a/100*7)+a;
            float  c=(float)b;
            System.out.println(f);
            System.out.println(c);

            if(c>f)
            {
                System.out.println("NO");
            }
            else
            {
                System.out.println("YES");

            }

        }
    }
}
