import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String in = sc.next();
        int a = sc.nextInt();
        int cnt = 0;
        for(int i = 0; i<a; i++){
            String k = sc.next();
            if(k.equals(in)){
                cnt++;
            }
        }
        System.out.print(cnt);
    }
}