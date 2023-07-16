import java.lang.*;
public class Q6 {
    public static void main(String[] args) {
        int n = 1, i = 1;
        do
        {
            do
            {
                System.out.print(n*i + "\t");
                i+=1;
            }while(i<11);
            System.out.print("\n");
            n+=1;
            i=1;
        }while(n<11);
    }
}
