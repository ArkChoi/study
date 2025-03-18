package Project.Tetris;

public class Map {

    void wall_set_up(int [][] map){ //처음 기초 셋업을 위한 메소드드
        //private int x = map.length; //이거 왜 안됨?
        int x = map.length; //x길이 구하기
        int y = map[0].length; //y길이 구하기
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){ 
                if( i==0 || j==0 || i==(y-1) || j==(x-1)){ //가장 마지막단 배열위치는 벽을 구성함
                    map[i][j]=99;
                }
                else{
                    map[i][j]=0;
                }
            }
        }
    }

    void print_map(int [][] map){ //게임 장면 프린트용 메소드
        int x = map.length; //x길이 구하기
        int y = map[0].length; //y길이 구하기
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){ 
                System.out.print("%d ");
            }
            System.out.println();
        }
    }
}
