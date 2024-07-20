import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int[] in = new int[6];
        int count = 0;
        int a = 1;
        int k = 0;
        for(int i = 0; i<6;i++){
            in[i] = sc.nextInt();
        }
        
        int T = sc.nextInt();
        int P = sc.nextInt();
        Arrays.sort(in);
        
        while(true){
            if(in[k]<=T*a){
//                System.out.printf("in[%d] %d\n",k, in[k]);
                if(in[k]==0){
                    count--;
                }
                count++;
                k++;
//                System.out.printf("count %d\n",count);
//                System.out.printf("k %d\n",k);
                a=1;
            }else{
                a++;
                count++;
//                System.out.printf("a %d\n",a);   
            }
            if(k==6){
                break;
            }
        }
        System.out.println(count);
        System.out.printf("%d %d", num/P, num%P);
    }
}