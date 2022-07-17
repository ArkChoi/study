import java.util.Scanner;

public class study1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String id = args[0];
        String pw;
        if(id.equals("qwer")){
            pw=sc.nextLine();
            if(pw.equals("qaz")){
                System.out.println("Success.");
            }
        }
        else{
            System.out.println("False.");
        }
    }
}
