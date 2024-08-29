import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        
        N = N*100;
        if(N>=M){
            System.out.print("Yes");
        }else{
            System.out.print("No");
        }
    }
}