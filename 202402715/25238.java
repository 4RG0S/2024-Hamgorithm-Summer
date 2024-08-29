import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        a = a*(100-b)/100;
        if(a>99){
            System.out.print(0);
        }else{
            System.out.print(1);
        }
    }
}