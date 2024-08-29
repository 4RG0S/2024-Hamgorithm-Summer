import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String num = sc.next();
        int tem = 0;
        for(int i = 0; i<num.length(); i++){
            tem = (tem*10 + (num.charAt(i) - '0'))%20000303;
        }
        System.out.print(tem);
    }
}