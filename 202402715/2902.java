import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String in = sc.next();
        int i = 0;
        while(true){
            if(in.charAt(i)>64&&in.charAt(i)<91){
                System.out.print(in.charAt(i));
                i++;
            }else{
                i++;
            }
            if(i==in.length()){
                break;
            }
        }
    }
}