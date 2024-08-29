import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        for(int i = 0; i<a; i++){
            String b = sc.next();
            int l = b.length();
            char k = b.charAt(l-1);
            
            
            
            if(k%2==1){
                System.out.println("odd");
            }else{
                System.out.println("even");
            }
        }
    }
}