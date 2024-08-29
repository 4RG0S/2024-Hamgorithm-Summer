import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String in = sc.next();
        int a = 0; // 커서 위치
        int count = 1; //출력
        while(true){
            if(a+1==in.length()){
                break;
            }
            
            if(in.charAt(a)>in.charAt(a+1)){
//                System.out.print(in.charAt(a));
//                System.out.print("\n");
                a++;
                count++;
            }else if(in.charAt(a)==in.charAt(a+1)){
                a++;
                count++;
            }else{
//                System.out.print(in.charAt(a));
                a++;
            }


        }
        System.out.print(count);
    }
}