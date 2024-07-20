import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int in = sc.nextInt();
		while(true) {
			if(in==1) {
				System.out.print("1");
				break;
			}
			if(in%2==1) {
				System.out.print("0");
				break;
			}else {
				in = in/2;
			}
		}
	}
}