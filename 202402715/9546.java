import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int out = 1;
        for(int i = 0; i<a;i++){
            int k = sc.nextInt();
            for(int j = 0; j<k;j++){
                out = out * 2;
            }
            System.out.println(out-1);
            out = 1;
        }
    }
}