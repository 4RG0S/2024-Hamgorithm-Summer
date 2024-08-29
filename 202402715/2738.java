import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        
        int[][] v1 = new int[x][y];
        for(int i = 0; i<y;i++){
            for(int j = 0; j<x;j++){
                v1[j][i]=sc.nextInt();
            }
        }
        int[][] v2 = new int[x][y];
        for(int i = 0; i<y;i++){
            for(int j = 0; j<x;j++){
                v2[j][i]=sc.nextInt();
            }
        }
        int[][] v3 = new int[x][y];
        for(int i = 0; i<y;i++){
            for(int j = 0; j<x;j++){
                v3[j][i]=(v1[j][i])+(v2[j][i]);
            }
        }
        
        for(int i = 0; i<y;i++){
            for(int j = 0; j<x;j++){
            System.out.printf("%d",v3[j][i]);
            if(j<x-1) {
            	System.out.print(" ");
            }
            }
            if(i<y-1) {
            	System.out.println();
            }
        }
    }
}