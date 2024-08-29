import java.util.*;
public class Main{
    public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
    	double a = sc.nextInt();
    	double b = sc.nextInt();
    	double c = sc.nextInt();

    	if(a*b/c>a/b*c) {
    		System.out.print((int)(a*b/c));
    	}else {
    		System.out.print((int)(a/b*c));
    	}
    }
}