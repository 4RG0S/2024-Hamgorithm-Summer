import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int l = sc.nextInt();
        int even = 0;
        int odd = 0;
        String k = sc.next();
        for(int i = 0; i<l;i++){
            if(k.charAt(i)%2==0){
                even++;
            }else{
                odd++;
            }
        }
        if(even>odd){
            System.out.print("0");
        }else if(odd>even){
            System.out.print("1");
        }else{
            System.out.print("-1");
        }
    }
}