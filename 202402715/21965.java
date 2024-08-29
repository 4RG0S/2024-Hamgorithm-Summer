import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int[] a = new int[num];
        boolean up = true;
        for(int i = 0; i<num; i++){
            a[i] = sc.nextInt();
        }
        for(int i = 1; i<num;i++){
//            System.out.print(i);
            if(up == true){
//            System.out.println("d");
                if(a[i-1] > a[i]){
                    up = false;
//                    System.out.println(up);
                }
            }else {
                if(a[i-1]<a[i]){
                    System.out.print("NO");
                    System.exit(0);
                }
            }
            
            if(a[i-1] == a[i]){
                    System.out.print("NO");
                    System.exit(0);
            }
            
            if(i == num-1){
                System.out.print("YES");
                System.exit(0);
            }
        }
    }
}