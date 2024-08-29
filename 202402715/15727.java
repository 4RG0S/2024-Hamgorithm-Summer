import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        for(int i = 0 ;i<num;i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
                
            int k = c % a;
            int t = c / a;

            if(a*b==c){
                if(b<10){
                    System.out.println(""+a+0+b);
                }else{
                    System.out.println(""+a+b);
                }
            }else if(k==0){
                if(t<10){
                    System.out.println(""+a+0+t);
                }else{
                    System.out.println(""+a+t);
                }
            }else{
                t=t+1;
                if(t<10){
                    System.out.println(""+k+0+t);
                }else{
                    System.out.println(""+k+t);
                }
            }
        }
    }
}