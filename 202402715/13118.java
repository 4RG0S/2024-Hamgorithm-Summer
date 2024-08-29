import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[] num = new int[4];
        for(int i = 0; i<4; i++){
            num[i]=sc.nextInt();
        }
        int x = sc.nextInt();
        int a= 0;
        while(true){
            if(x==num[a]){
                System.out.print(a+1);
                break;
            }
            a++;
            if(a==4){
                System.out.print(0);
                break;
            }
        }
    }
}