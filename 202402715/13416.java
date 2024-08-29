import java.util.Arrays;
import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		for(int i = 0; i<a; i++) {
			int b = sc.nextInt();
			int sum = 0;
			for(int j = 0; j<b; j++) {
				int[] v = {sc.nextInt(), sc.nextInt(), sc.nextInt()};
				Arrays.sort(v);
				if(v[2]>0) {
					sum = sum + v[2];
				}
			}
			System.out.println(sum);
		}
	}
}