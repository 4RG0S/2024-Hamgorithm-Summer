import java.util.*;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		for(int i = 0; i<a; i++) {
			int b = sc.nextInt();
			String[][] in = new String[b][2];
			for(int j = 0; j<b;j++) {
				in[j][0] = sc.next();
				in[j][1] = sc.next();
			}
			
		
			Arrays.sort(in, new Comparator<String[]>() {
				
	            public int compare(String[] o1, String[] o2) {
	                return Integer.valueOf(o1[1]).compareTo(Integer.valueOf(o2[1]));
	            }			
	        });
			
			/*for(int k = 0; k<2; k++) {
				for(int j = 0; j<b;j++) {
					System.out.print(in[j][k]);
					System.out.println();
				}
			}*/
			System.out.println(in[b-1][0]);
		}
		

	}
}