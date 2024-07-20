import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String in = sc.next();
		int count = in.charAt(0)-'A';
		if(count > 13) {
			count = 26 - count;
		}
		
		int ln = in.length();
		for(int i = 0; i < ln-1; i++) {
			int a = in.charAt(i)-in.charAt(i+1);
			if(a > 13) {
				a = 26 - a;
			}else if(a<-13) {
				a = a + 26;
			}
			if(a<0) {
				a = a*(-1);
			}
			
//			System.out.println(a);
			count = count + a;
		}
		System.out.print(count);
	}
}