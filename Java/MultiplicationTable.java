import java.util.Scanner;

public class MultiplicationTable {
    public static void main(String[] args) {
        int gub,FristNum;
        Scanner sc = new Scanner(System.in);
        FristNum=sc.nextInt();
        for(int i=1;i<10;i++){
            gub=FristNum*i;
            System.out.println(FristNum+"X"+i+"="+gub);
        }
        sc.close();
    }
}
