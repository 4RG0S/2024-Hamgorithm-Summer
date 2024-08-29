import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int k = 1;
        while(true){
            int n0 = sc.nextInt();
            if(n0==0){
                break;
            }
            int n1 = n0*3;
            if(n1%2==0){
                System.out.printf("%d. %s %d\n", k, "even", n0/2);
                k++;
            }else{
                System.out.printf("%d. %s %d\n", k, "odd", (n0-1)/2);
                k++;
            }
        }
    }
}