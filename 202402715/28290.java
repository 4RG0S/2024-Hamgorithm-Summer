import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String in = sc.next();
        switch(in){
                case("fdsajkl;"): case("jkl;fdsa"):
                System.out.print("in-out");
                break;
                
                case("asdf;lkj"): case(";lkjasdf"):
                System.out.print("out-in");
                break;
                
                case("asdfjkl;"):
                System.out.print("stairs");
                break;
                
                case(";lkjfdsa"):
                System.out.print("reverse");
                break;
               
            default:
                System.out.print("molu");
        }
    }
}