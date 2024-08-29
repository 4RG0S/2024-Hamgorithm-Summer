import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String in = sc.next();
        int count = 0;
        int k = 0;
        LinkedList<Character> a = new LinkedList<>();
        for(int i = 0; i<in.length();i++){
            a.add(in.charAt(i));
        }
        while(true){

            
            if(a.get(k)<95){
                if((k%4)!=0){
                    for(int j = 0; j<4-k%4;j++){
                        a.add(j+k,'~');
                    }
                    for(int j = 0; j<k%4;j++){
                        k++;
                        count++;
                    }
                }
            }
            for(int q = 0; q<a.size();q++){
//                System.out.print(a.get(q));
            }
//            System.out.print(" + ");
//            System.out.println();

            k++;
            if(k==a.size()){
                break;
            }

            
        }
        System.out.print(count);
    }
}