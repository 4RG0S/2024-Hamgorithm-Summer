import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        a = a/2;
        int[] k = {a,b};
        Arrays.sort(k);
        System.out.print(k[0]);
    }
}