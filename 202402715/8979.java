import java.util.*;
public class Main{
    public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
    	int a = sc.nextInt();
    	int b = sc.nextInt();
    	int[][] arr = new int[a][4];
    	for(int i = 0; i<a;i++) {
    		for(int j = 0 ;j<4;j++) {
    			arr[i][j] = sc.nextInt();
    		}
    	}
    	
        Arrays.sort(arr, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[1] != o2[1]) {
                    return o2[1] - o1[1];
                } else if (o1[2] != o2[2]) {
                    return o2[2] - o1[2];
                } else {
                    return o2[3] - o1[3];
                }
            }
        });
        
        int rank = 1;
        for (int i = 0; i < a; i++) {
            if (i > 0 && 
                arr[i][1] == arr[i-1][1] && 
                arr[i][2] == arr[i-1][2] && 
                arr[i][3] == arr[i-1][3]) {
            	
            }else {
                rank = i + 1;
            }
            if (arr[i][0] == b) {
                System.out.println(rank);
                break;
            }
        }

    	/*for(int i = 0; i<a;i++) {
    		for(int j = 0 ;j<4;j++) {
    			System.out.print(arr[i][j]);
    		}
    		System.out.println();
    	}*/
    }
}