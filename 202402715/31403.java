import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        String k = Integer.toString(a);
        k = k + b;
        int d = Integer.parseInt(k);
        System.out.println(a+b-c);
        System.out.print(d-c);
    }
}