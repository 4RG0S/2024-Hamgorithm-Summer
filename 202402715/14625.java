import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int h1 = sc.nextInt();
		int m1 = sc.nextInt();
		int h2 = sc.nextInt();
		int m2 = sc.nextInt();
		int count = 0;
		int a = sc.nextInt();
		
		if(h2-h1==0) {
			if(h1/10==a||h1%10==a) {
				count = m2-m1+1;
			}else {
				for(int i = m1; i<m2;i++) {
					if(i/10==a||i%10==a) {
						count++;
					}
				}
			}
		}
		
		else {
			if(h1/10==a||h1%10==a) {
				count = count + 60 - m1;
			}else {
				for(int i = m1; i<60;i++) {
					if(i/10==a||i%10==a) {
						count++;
					}
				}
			}
			if(h2/10==a||h2%10==a) {
				count = count + m2;
			}else {
				for(int i = 0; i<m2+1;i++) {
					if(i/10==a||i%10==a) {
						count++;
					}
				}
			}
			for(int i = h1+1; i<h2;i++) {
				if(i/10==a||i%10==a) {
					count = count + 60;
				}else {
					for(int j = 0; j<60;j++) {
						if(j/10==a||j%10==a) {
							count++;
						}
					}
				}
			}
		}
		System.out.print(count);
		
	}
}