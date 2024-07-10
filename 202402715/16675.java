import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String m1 = sc.next();
        String m2 = sc.next();
        String t1 = sc.next();
        String t2 = sc.next();
        String m;
        String t;
        if(m1.equals(m2)){
            m = m1;
            switch(m){
                    case("R"):
                    if(t1.equals("P") || t2.equals("P")){
                        System.out.print("TK");
                    }else if(t1.equals("S") && t2.equals("S")){
                        System.out.print("MS");
                    }else{
                        System.out.print("?");
                    }break;
                    
                    case("P"):
                    if(t1.equals("S") || t2.equals("S")){
                        System.out.print("TK");
                    }else if(t1.equals("R") && t2.equals("R")){
                        System.out.print("MS");
                    }else{
                        System.out.print("?");
                    }break;
                    
                    case("S"):
                    if(t1.equals("R") || t2.equals("R")){
                        System.out.print("TK");
                    }else if(t1.equals("P") && t2.equals("P")){
                        System.out.print("MS");
                    }else{
                        System.out.print("?");
                    }break;
            }
            
        }else if(t1.equals(t2)){
            t = t1;
            switch(t){
                    case("R"):
                    if(m1.equals("P") || m2.equals("P")){
                        System.out.print("MS");
                    }else if(m1.equals("S") && m2.equals("S")){
                        System.out.print("TK");
                    }else{
                        System.out.print("?");
                    }break;
                    
                    case("P"):
                    if(m1.equals("S") || m2.equals("S")){
                        System.out.print("MS");
                    }else if(m1.equals("R") && m2.equals("R")){
                        System.out.print("TK");
                    }else{
                        System.out.print("?");
                    }break;
                    
                    case("S"):
                    if(m1.equals("R") || m2.equals("R")){
                        System.out.print("MS");
                    }else if(m1.equals("P") && m2.equals("P")){
                        System.out.print("TK");
                    }else{
                        System.out.print("?");
                    }break;
            }
        }else{
            System.out.print("?");
        }
    }
}