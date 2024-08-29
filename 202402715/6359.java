import java.util.*;
public class Main{
    public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
    	int a = sc.nextInt();
    	for(int i = 0 ;i<a;i++) {
    		int v = sc.nextInt();
    		int x = 0; 
    		while(true) {
    			if(x*x==v) {
    	    		System.out.println(x);
    	    		break;
    			}else if(x*x<v){
    				x++;
    			}else {
    	    		System.out.println(x-1);
    	    		break;
    			}
    		}
    	}
    }
}