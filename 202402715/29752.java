import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int in = sc.nextInt();
		int count = 0;
		int tem = 0;
		int mark = 0;
		int[] a = new int[in];
		for(int i = 0; i < in; i++) {
			a[i]=sc.nextInt();
		}
		
		for(int i = 0; i < in; i++) {
			if(a[i]!= 0) {
				tem++;
				if(tem>count) {
					count = tem;
				}
			}else {
				if(tem>count) {
					count = tem;
				}
				tem = 0;
				mark = 1;
			}
		}
		
		if(mark == 1) {
			System.out.print(count);
		}else {
			System.out.print(tem);
		}
	}
}