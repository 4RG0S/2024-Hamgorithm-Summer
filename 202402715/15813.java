import java.util.*;
public class Main{
    public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
    	int a = sc.nextInt();
    	String in = sc.next();
    	int cnt = 0;
    	for(int i = 0; i<a; i++) {
    		cnt = cnt + in.charAt(i);
    	}
    	cnt = cnt - 64*a;
    	System.out.print(cnt);
    }
}