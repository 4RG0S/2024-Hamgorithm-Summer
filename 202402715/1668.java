import java.util.*;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int cnt = 1;
		int[] arr = new int[k];
		
		for(int i = 0; i<k;i++) {
			arr[i] = sc.nextInt();
		}
		int num = arr[0];
		for(int i = 1; i<k; i++) {
			if(arr[i]>num) {
				num = arr[i];
				cnt++;
			}
		}
		System.out.println(cnt);
		cnt = 1;
		num = arr[k-1];
		for(int i = k-1; i>-1; i--) {
			if(arr[i]>num) {
				num = arr[i];
				cnt++;
			}
		}
		System.out.print(cnt);
	}
}