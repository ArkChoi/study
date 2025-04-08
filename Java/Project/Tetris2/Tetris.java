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
            //미숙지 코드 시작위치
            final String os = System.getProperty("os.name"); //os정보를 받아오는 듯 하다 아직 미숙지
            if(os.contains("Windows")){ //Windows 일때 시행하는 듯 하다 아직 미숙지
                new ProcessBuilder("cmd","/c","cls").inheritIO().start().waitFor(); //여기는 완전 미숙지 부분
            }
            else{ //Linux를 상정해 둔 듯 하다, 예외처리 부분 미숙지
                Runtime.getRuntime().exec("clear"); //Linux 명령어를 시행했다.. 메소드 미숙지
            }
            //종결위치
            System.out.flush();
            main_map.map_print();
            life = main_map.cheak_block();//life를 통해 패배 조건 형성
            System.out.println();//맵 아직 초기화를 안해서 표현상 한칸 띄기
            Thread.sleep(250); //시간 밀리세크로 대기시키는 코드, 1000이 1초이다. throws 문을 만든 장본인
        }
    }
}
