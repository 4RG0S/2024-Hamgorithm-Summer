import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String in = sc.next();
        
        if(in.charAt(0)=='E'){
            System.out.print("I");
        }else{
            System.out.print("E");
        }

        if(in.charAt(1)=='N'){
            System.out.print("S");
        }else{
            System.out.print("N");
        }

        if(in.charAt(2)=='F'){
            System.out.print("T");
        }else{
            System.out.print("F");
        }

        if(in.charAt(3)=='P'){
            System.out.print("J");
        }else{
            System.out.print("P");
        }        
    }
}