import java.util.*;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String in = sc.next();
		int k = sc.nextInt();
		String[][] arr = new String[k][k];
		String[][] narr = new String[k][k];
		
		for(int i = 0; i<k;i++) {
			for(int j = 0; j<k;j++) {
				arr[i][j] = ""+sc.nextInt();
			}
		}
		for(int i = 0; i<k;i++) {
			for(int j = 0; j<k;j++) {
				if(arr[i][j].equals("2")) {
					arr[i][j] = ""+5;
				}else if(arr[i][j].equals("5")) {
					arr[i][j] = ""+2;
				}else if(arr[i][j].equals("1") || arr[i][j].equals("8")) {
				}else {
					arr[i][j] = "?";
				}
			}
		}
		
		switch(in) {
		case("L"):
			for(int i = 0; i<k;i++) {
				for(int j = k; j>0;j--) {
					System.out.printf("%s ", arr[i][j-1]);
				}
				System.out.println();
			}
			break;
		case("R"):
			for(int i = 0; i<k;i++) {
				for(int j = k; j>0;j--) {
					System.out.printf("%s ", arr[i][j-1]);
				}
				System.out.println();
			}
			break;
		case("U"):
			for(int i = k; i>0;i--) {
				for(int j = 0; j<k;j++) {
					System.out.printf("%s ", arr[i-1][j]);
				}
				System.out.println();
			}
			break;
		case("D"):
			for(int i = k; i>0;i--) {
				for(int j = 0; j<k;j++) {
					System.out.printf("%s ", arr[i-1][j]);
				}
				System.out.println();
			}
			break;
		}
		
	}
}