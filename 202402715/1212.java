import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        int b = sc.nextInt();
        char[][] in = new char[q][q];
        for(int j = 0; j<q;j++){
            String k = sc.next();
            for(int i = 0; i<q;i++){
                in[j][i] = k.charAt(i);
            }
        }

        if(b==1){
            for(int j = 0; j<q;j++){
                for(int i = 0; i<q;i++){
                    switch(in[j][i]){
                     case('d'): in[j][i]='q';
                            break;
                     case('b'): in[j][i]='p';
                            break;
                     case('q'): in[j][i]='d';
                            break;
                     case('p'): in[j][i]='b';
                            break;
                    }
                }
            }
        }else{
            for(int j = 0; j<q;j++){
                for(int i = 0; i<q;i++){
                    switch(in[j][i]){
                     case('d'): in[j][i]='b';
                            break;
                     case('b'): in[j][i]='d';
                            break;
                     case('q'): in[j][i]='p';
                            break;
                     case('p'): in[j][i]='q';
                            break;
                    }
                }
            }
        }



        //배열 출력
        for(int j = 0; j<q;j++){
            for(int i = 0; i<q;i++){
                System.out.print(in[j][i]);
            }
            System.out.println();
        }
    }
}