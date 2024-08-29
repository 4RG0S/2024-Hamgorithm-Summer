import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int in = sc.nextInt();
		if(620<=in && in<=780) {
			System.out.print("Red");
		}else if(590<=in && in<620) {
			System.out.print("Orange");
		}else if(570<=in && in<590) {
			System.out.print("Yellow");
		}else if(495<=in && in<570) {
			System.out.print("Green");
		}else if(450<=in && in<495) {
			System.out.print("Blue");
		}else if(425<=in && in<450) {
			System.out.print("Indigo");
		}else if(380<=in && in<425) {
			System.out.print("Violet");
		}
	}
}