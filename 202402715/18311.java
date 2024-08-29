import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		long b = sc.nextLong();
		long[] arr = new long[a*2+1];
		long[] a2 = new long[a];
		
		for(int i = 0; i<a;i++) {
			a2[i] = sc.nextInt();
		}
		for(int i = 0; i<a+1;i++) {
			if(i==0) {
				arr[i] = 0;
			}else {
				arr[i]=a2[i-1]+arr[i-1];
			}
		}
		for(int i = a+1; i<a*2+1;i++) {
			arr[i]= arr[i-1]+a2[a*2-i];
		}
		
		for(int i = 0; i<a*2;i++) {
			if(arr[i]<b&&b<arr[i+1]) {
//                System.out.printf("c1   %d\n", i);
                if(i==a){
                  System.out.print(i);
//					System.out.println();
                }
                else if(i>a) {
					System.out.print(a*2-i);
//					System.out.println();
				}else {
					System.out.print(i+1);
//					System.out.println();
				}
			}else if(b==arr[i]){
//                System.out.printf("c2   %d\n", i);
                if(i==a){
                  System.out.print(i);
//					System.out.println();
                }
                else if(i>a) {
					System.out.print(a*2-i);
//					System.out.println();
				}else {
					System.out.print(i+1);
//					System.out.println();
				}
            }
        }
		
		
		
//		for(int i = 0; i<a*2+1; i++) {
//			System.out.println(arr[i]);
//		}
	}
}