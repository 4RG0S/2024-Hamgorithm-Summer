import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String k = sc.next();
        int a = k.length();
        boolean m = false;
        boolean o = false;
        boolean b = false;
        boolean i = false;
        boolean s = false;
        boolean out = true;
        
        for(int d = 0; d<a; d++){
            switch(k.charAt(d)){
            case'M': m = true; break;
            case'O': o = true; break;
            case'B': b = true; break;
            case'I': i = true; break;
            case'S': s = true; break;
            }
        }
        
        if(m&&o&&b&i&&s) {
        	System.out.print("YES");
        }else {
        	System.out.print("NO");
        }
    }
}