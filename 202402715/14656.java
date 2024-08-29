import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int count = 0;
        for(int i = 0; i<a;i++){
            if(sc.nextInt()!=i+1){
                count++;
            }
        }
        System.out.print(count);
    }
}