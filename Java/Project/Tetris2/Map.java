package Project.Tetris2;

class Map {
    //필드 부분
    private int y;
    private int x;
    private int[][] map;
    //생성자 메소드
    Map(int x, int y){
        this.x=x;
        this.y=y;
        map = new int[y][x];
    }
    //메소드 부분
    int x_get(){ //x의 길이를 알려주는 역활
        return x;
    }
    int y_get(){ //y의 길이를 알려주는 역활
        return y;
    }

    void wall_setup(){ //기초 벽 세팅하는 역활
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                if( i==0 || j==0 || i==(y-1) || j==(x-1) ){
                    map[i][j]=35;
                }
                else{
                    map[i][j]=0;
                }
            }
        }
    }

    void map_print(){ // 2차배열의 맵을 출력하는 역활
        for(int i=0;i<y;i++){
            for(int num : map[i]){
                if(num==0){
                    System.out.print(num+" ");
                }
                else{
                    System.out.printf("%c ",num); // 야 이거 방금전에 배웠는데 print로는 변수(형식 지시자) 출력이 안되네요? (형식 지시자 % 를 사용하는 변수를 지칭)
                }
            }
            System.out.println();
        }
    }
}
