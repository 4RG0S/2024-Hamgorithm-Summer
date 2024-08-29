import java.util.*;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		if(a==0) {
			System.out.print(1);
		}else {
			for(long i = a-1; i>0;i--) {
				a = a*i;
			}
			System.out.print(a);
		}
	}
}