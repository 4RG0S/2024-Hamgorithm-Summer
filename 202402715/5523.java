import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int A = 0;
		int B = 0;
		for(int i = 0; i<a; i++) {
			int b = sc.nextInt();
			int c = sc.nextInt();
			if(b>c) {
				A++;
			}else if(c>b) {
				B++;
			}
		}
		System.out.printf("%d %d", A, B);
	}
}