import java.util.*;
public class Main{
    public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
    	int N = sc.nextInt();
    	int W = sc.nextInt();
    	int H = sc.nextInt();
    	int L = sc.nextInt();
    	
    	W = W/L;
    	H = H/L;
    	if(W*H<N) {
    		System.out.print(W*H);
    	}else {
    		System.out.print(N);
    	}
    }
}