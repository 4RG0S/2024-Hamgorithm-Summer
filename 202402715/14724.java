import java.util.Arrays;
import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int[] m = new int[9];
		int[] n = new int[9];
		int[] k = new int[a];
		String[] q = {"PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY"};
		for(int i = 0; i<9; i++) {
			for(int j = 0; j<a;j++) {
				k[j] = sc.nextInt();
			}
			Arrays.sort(k);
			m[i] = k[a-1];
			n[i] = k[a-1];
		}
		Arrays.sort(m);
		for(int i = 0; i<9; i++) {
//			System.out.printf("%d  %d\n", m[i], n[i]);
			if(n[i] == m[8]) {
				System.out.println(q[i]);
			}
		}
	}
}