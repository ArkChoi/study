package Project.Tetris2;

import java.io.IOException;

public class Tetris {
    public static void main(String[] args) throws InterruptedException, IOException {
        Block main_map = new Block(11, 21);
        int block_movig = 0; //블럭의 움직임을 main 클레스에서 총괄
        boolean life = true; //테스트용 코드

        main_map.wall_setup();

        System.out.println("X 크기 : "+main_map.x_get());
        System.out.println("Y 크기 : "+main_map.y_get());

        while(life){ //무한 반복
            System.out.flush();
            main_map.map_print();
            life = main_map.cheak_block();//life를 통해 패배 조건 형성
            System.out.println();//맵 아직 초기화를 안해서 표현상 한칸 띄기
            Thread.sleep(1000); //시간 1초를 대기시키는 코드 throws 문을 만든 장본인
        }
    }
}
