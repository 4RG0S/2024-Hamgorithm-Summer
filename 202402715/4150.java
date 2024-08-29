import java.util.Scanner;
import java.math.*;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		if(a==1||a==2) {
			System.out.print(1);
			System.exit(0);
		}
		BigInteger v1 = BigInteger.valueOf(1);
		BigInteger v2 = BigInteger.valueOf(1);
		BigInteger s = BigInteger.valueOf(0);
		for(int i = 0; i<a-2;i++) {
			s = v1.add(v2);
			v1 = v2;
			v2 = s;
		}
		System.out.print(s);

	}
}