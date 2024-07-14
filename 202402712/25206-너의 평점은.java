import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args)throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
				
		double sum =0;
		double score =0;
		
		for(int i=0;i<20;i++) {
			StringTokenizer St = new StringTokenizer(br.readLine());
			String S = St.nextToken();
			double test = Double.parseDouble(St.nextToken());
			String st = St.nextToken();
			
			switch(st) {
				case "A+":
					sum += test*4.5;
					score += test;
					break;
				case "A0":
					sum += test*4.0;
					score += test;
					break;
				case "B+":
					sum += test*3.5;
					score += test;
					break;
				case "B0":
					sum += test*3.0;
					score += test;
					break;
				case "C+":
					sum += test*2.5;
					score += test;
					break;
				case "C0":
					sum += test*2.0;
					score += test;
					break;
				case "D+":
					sum += test*1.5;
					score += test;
					break;
				case "D0":
					sum += test*1.0;
					score += test;
					break;
				case "F":
					sum += test*0.0;
					score += test;
					break;
			}
		}
		System.out.printf("%.6f", sum/score);
		br.close();
	}
}