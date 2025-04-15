package Project.Moving;

import java.util.Scanner;

public class Moving {
    public static void main(String[] args){
        Map map = new Map(10, 10);
        boolean play = true;
        Scanner sc = new Scanner(System.in);
        String input;
        
        map.wall_setup();
        map.playing();
        while(play){
            map.map_print();
            input=sc.next(); //문제점 enter를 눌러야만 작동하게 대기중임
            if(input.equals("q")){
                play=false;
                System.out.println("Game Stop!");
            }
            map.move(input.charAt(0));
        }
        sc.close();
    }
}
