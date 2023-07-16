import java.lang.*;
import java.util.Scanner;

public class Q5 {

    public static void main(String[] args) {
        Scanner s= new Scanner(System.in);
        System.out.print("\nEnter the radius of Circle : ");

        double r= s.nextDouble();
        System.out.print("Area of Circle is: " + 3.14*r*r);

        System.out.print("\nEnter the length and breadth of Rectangle :");
        int l=s.nextInt();
        int b=s.nextInt();
        System.out.print("Area of Rectangle is: " + l*b);

        System.out.print("\nEnter the length of side of Square :");
        int sl=s.nextInt();
        System.out.print("Area of Square is: " + sl*sl);
    }
}
