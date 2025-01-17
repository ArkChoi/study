package gugudan;

import java.util.Scanner;

public class point{
    private String name;
    int x;
    int y;

    public point(String name, int x, int y){
        this.name=name;
        this.x=x;
        this.y=y;
    }

    public void where(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("구구단 프로그램입니다.\n x*y=z 수식입니다.\n");
        System.out.print("x 를 입력해 주세요 : ");
        this.x = scanner.nextInt() - 1;
        System.out.print("y 를 입력해 주세요 : ");
        this.y = scanner.nextInt() - 1;
        scanner.close();
    }
}