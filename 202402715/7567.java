import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String in = sc.next();
		int count = 10;
		for(int i = 1; i<in.length(); i++) {
			if(in.charAt(i)==in.charAt(i-1)) {
				count = count+5;
			}else {
				count = count+10;
			}
		}
		System.out.print(count);
	}
}