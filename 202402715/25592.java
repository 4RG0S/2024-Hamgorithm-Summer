import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int count = 0;
        int a = 0;
        boolean sign = false;
        int in = sc.nextInt();
        while(true){
            if(in<count || in==count){
                sign = true;
                break;
            }else{
                a++;
                count = count + a;
            }
        }
        if(a%2==0&&count-in==0){
            System.out.print(a+1);
        }else if(a%2==1){
            System.out.print(count-in);
        }else if(a%2==0){
            System.out.print("0");
        }
    }
}