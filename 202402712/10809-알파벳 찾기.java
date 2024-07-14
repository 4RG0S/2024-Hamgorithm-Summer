import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int[] a = new int[26];		
		for(int i=0;i<a.length;i++) a[i] = -1;
		
		String S = st.nextToken();
		
		for(int i = 0; i < S.length(); i++) {
			char ch = S.charAt(i);
		    
			if(a[ch - 'a'] == -1) {
				a[ch - 'a'] = i;
			}
		}
		
		for(int v : a) {
			bw.write(v+" ");
		}
		
		bw.flush();
		bw.close();
		br.close();
	}
}
