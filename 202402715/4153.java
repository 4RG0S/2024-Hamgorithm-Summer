import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        while(true){
            int[] a = {sc.nextInt(), sc.nextInt(), sc.nextInt()};
            if(a[1]==0){
                break;
            }
            Arrays.sort(a);
            for(int i = 0; i<3;i++){
                a[i] = a[i]*a[i];
            }
            if(a[2]==a[1]+a[0]){
                System.out.println("right");
            }else{
                System.out.println("wrong");
            }
        }
    }
}