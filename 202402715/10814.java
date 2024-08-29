import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		String[][] in = new String[a][3];
		int q = 0;
		for(int i = 0; i<a;i++) {
				in[i][0] = sc.next();
				in[i][1] = sc.next();
				in[i][2] = ""+q;
				q++;
		}
        Arrays.sort(in, new Comparator<String[]>() {
            public int compare(String[] o1, String[] o2) {
                int firstComparison = Integer.compare(Integer.parseInt(o1[0]), Integer.parseInt(o2[0]));
                if (firstComparison==0) {
                    return Integer.compare(Integer.parseInt(o1[2]), Integer.parseInt(o2[2]));
                }
                return firstComparison;
            }
        });
        
		for(int i = 0; i<a;i++) {
			System.out.printf(in[i][0] + " " +in[i][1] + "\n");
		}
		
	}
}