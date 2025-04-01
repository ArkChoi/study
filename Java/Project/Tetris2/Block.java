package Project.Tetris2;

public class Block extends Map{
    int block;
    int block_x;
    int block_y;

    Block(int x, int y){//생성자가 재 정의 되는것이 무조건 있어야 한다고 한다.
        super(x, y);//부모 클레스의 생성자 불러오기
    }

    boolean cheak_block(){
        block=0; //블럭 체크용 변수
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                if(map[i][j]==91){//블럭을 찾았다고 알림, 위치 기억
                    block = 1;
                    block_x = j;
                    block_y = i;
                }
            }
        }
        if(block == 0){ //블럭을 못 찾았다면
            block=create_block();
            if(block==0){ //게임오버 기준.
                System.out.println("Game Over!");
                return false;
            }
        }
        else{ //블럭을 찾았다면
            falling_block();
        }
        return true;
    }
    
    int create_block(){ //밑에 블럭 생성에서 보다 싶이 완전 테트리스 전용임
        block_x = (x_get()/2); //블럭 x 축에 중앙 찾기
        block_y = 1; //블럭 y 축에 칸 밑으로 보내기기
        if(map[block_y][block_x]==0){ //생성위치에 블럭이 없다면
            map[block_y][block_x] = 91; //블럭 생성
            return 1;
        }
        else{ //생성위치에 블럭이 있으면
            return 0;
        }
        //아직은 코드가 없으나 블럭 구조를 그리는 메소드가 추가되어야함
    }

    void falling_block(){ //고민중인 부분 블럭이 떨어지는 것을 구현 (고민은 다른 클레스로 뺄 것 인가?)
        if(map[block_y+1][block_x]==0){ //밑에 공간이 비어있다면
            map[block_y+1][block_x] = 91; //1칸 밑 공간으로 내리기
            map[block_y][block_x] = 0; //위에있던 블럭 제거
        }
        else{// 밑에 어떠한 형태라도 블럭이 있다면
            map[block_y][block_x] = 92; //임시 코드니 정지 블럭 나중에 바꿔
        }
    }
}