import java.util.*;
public class Main{
    public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
    	int a = sc.nextInt();
    	int[][] arr = new int[2][a];
    	int[] cnt = new int[31];
    	for(int i=0;i<a;i++) {
    		arr[0][i] = sc.nextInt();
    		arr[1][i] = sc.nextInt();
    	}
    	int num = sc.nextInt();
    	
    	for(int i = 0; i<a;i++) {
    		for(int j = arr[0][i]+1; j < arr[1][i] + 1; j++) {
    			cnt[j-1]++;
    		}
    	}
    	
    	for(int i = 0; i<32;i++) {
    		if(i==31) {
    			System.out.print(1);
    			break;
    		}
    		if(cnt[i]>num) {
    			System.out.print(0);
    			break;
    		}
    	}
    }
}