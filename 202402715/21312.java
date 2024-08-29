import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[] a = new int[3];
        for(int i = 0; i<3;i++){
            a[i] = sc.nextInt();
        }
        int[] b = {a[0], a[1], a[2]};
        int out= 0;
        int odd = 0;
        for(int i = 0; i<3;i++){
            if(a[i]%2==1){
                odd++;
            }
            a[i] = a[i]*(a[i]%2);
            if(a[i]==0){
                a[i]++;
            }
        }
        if(odd == 0){
            System.out.print(b[0]*b[1]*b[2]);
        }else{
            System.out.print(a[0]*a[1]*a[2]);
        }
    }
}