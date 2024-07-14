import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N =sc.nextInt();
		double[] test = new double[N];
		double M =0, sum=0;
		double result = 0;
		
		for(int i=0;i<N;i++) {
			test[i] = sc.nextInt();
			
			if(M<test[i]) M = test[i];
		}
		
		sc.close();
		
		for(int i=0;i<N;i++) {
			test[i] = (test[i]/M)*100;
			sum += test[i];
		}
		
		result = sum/N;
		System.out.println(result);
		
	}

}