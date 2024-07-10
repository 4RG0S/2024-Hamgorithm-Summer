import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String in = sc.next();
		char[] k = {'K', 'O','R', 'E', 'A'};
		int j = 0;
		int count = 0;
		for(int i = 0; i<in.length();i++) {
			if(in.charAt(i) == k[j]) {
				count++;
				j++;
			}
			if(j==5) {
				j=0;
			}
		}
		
		System.out.println(count);
	}
	
}