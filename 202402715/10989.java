import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
       
		int a = Integer.parseInt(br.readLine());		
		int[]num = new int[a];
		
		for(int i = 0; i<a;i++) {
			num[i]= Integer.parseInt(br.readLine());
		}
			
		Arrays.sort(num);
		
		for(int i = 0; i<a; i++) {
			sb.append(num[i]).append('\n');
		}
		System.out.println(sb);
	}
}