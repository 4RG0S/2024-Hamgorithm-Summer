import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int k = sc.nextInt();
        int[] a = new int[num];
        for(int i = 0; i<k*2;i++){
            int t = sc.nextInt();
            a[t-1]++;
        }
        for(int i = 0; i<num;i++){
        System.out.println(a[i]);
        }
    }
}