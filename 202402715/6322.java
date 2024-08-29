import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int i = 1;
		while(true) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			
			if(a==0) {
				break;
			}
			System.out.printf("Triangle #%d\n", i);
			
			if(c == -1) {
				System.out.printf("c = %.3f\n",(double)Math.sqrt(a*a + b*b));
			}else if(a == -1){
				if((c*c - b*b)<0 || (c*c - b*b)==0) {
					System.out.println("Impossible.");
				}else {
					System.out.printf("a = %.3f\n",(double)Math.sqrt(c*c - b*b));
				}
			}else if(b == -1) {
				if((c*c - a*a)<0 || (c*c - a*a)==0) {
					System.out.println("Impossible.");
				}else {
					System.out.printf("b = %.3f\n",(double)Math.sqrt(c*c - a*a));
				}
			}
			System.out.println();
			i++;
		}	
	}
}