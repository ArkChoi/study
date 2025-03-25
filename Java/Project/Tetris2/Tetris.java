package Project.Tetris2;

public class Tetris {
    public static void main(String[] args) {
        Block main_map = new Block(11, 21);
        int block_movig = 0; //블럭의 움직임을 main 클레스에서 총괄
        int life = 0; //테스트용 코드

        main_map.wall_setup();

        System.out.println("X 크기 : "+main_map.x_get());
        System.out.println("Y 크기 : "+main_map.y_get());

        while(life<5){ // 아직 일부로 무한 반복은 안 시키고 있다.
            main_map.map_print();
            main_map.cheak_block();//이번 추가 코드
            System.out.println();//맵 아직 초기화를 안해서 표현상 한칸 띄기
            life++;
        }
    }
}
