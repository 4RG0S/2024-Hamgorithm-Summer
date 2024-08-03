import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        System.out.print(a*78/100);
        System.out.print(" ");
        System.out.print(a- a*20/100*22/100);
    }
}