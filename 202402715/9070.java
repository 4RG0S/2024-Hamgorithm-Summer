public class m {
    
}
import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        for(int i = 0; i<k;i++){
            
            int b = sc.nextInt();
            int[][] in = new int[b][2];
            for(int j = 0;j<b;j++){
                int a = sc.nextInt();
                int x = sc.nextInt();
                in[j][0] = (a*10000)/x;
                in[j][1] = x;
            }
            Arrays.sort(in, (o1,o2) -> (o1[0] == o2[0] ? o1[1] - o2[1] : o2[0] - o1[0]));            
            System.out.println(in[0][1]);
            /*
            for(int j = 0; j < b; j++){
            System.out.println(in[j][0] + " "+in[j][1]);
        }
            System.out.println();
            */
        }
    }
}