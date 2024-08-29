import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		b = b*b;
		int c = sc.nextInt();
		c = c*c;
		for(int i = 0; i<a; i++) {
			int k = sc.nextInt();
			if(k*k<=b+c) {
				System.out.println("DA");
			}else {
				System.out.println("NE");
			}
		}
	}
}