import java.util.*;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int[] in = new int[a];
		int odd = 0;
		int even = 0;
		for(int i = 0; i < a;i++) {
			in[i] = sc.nextInt();
		}
		
		for(int i = 0; i < a;i++) {
			if(in[i]%2==0) {
				even++;
			}else {
				odd++;
			}
		}
		
		if(odd-even>1 || even-odd>1) {
			System.out.print(0);
		}else if(odd==even) {
			System.out.print(1);
		}else if(odd-even==1) {
			System.out.print(1);
		}else if(even-odd==1) {
			System.out.print(0);
		}
	}
}