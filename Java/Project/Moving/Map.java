package Project.Moving;

public class Map {
    int y;
    int x;
    int[][] map;

    //생성자 메소드
    Map(int x, int y){
        this.x=x;
        this.y=y;
        map = new int[y][x];
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
                    System.out.printf("%c ",num);
                }
            }
            System.out.println();
        }
    }

    void playing(){
        int x_half = x/2;
        int y_half = y/2;
        map[y_half][x_half]=97;
    }

    void move(char str){
        boolean cheak = false;
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                if(map[i][j]==97){
                    switch (str) {
                        case 'w':
                            map[i-1][j]=97;
                            map[i][j]=0;
                            cheak = true;
                            break;
                        case 'a':
                            System.out.println(j+" a");
                            map[i][j+1]=97;
                            map[i][j]=0;
                            cheak = true;
                            break;
                        case 's':
                            map[i+1][j]=97;
                            map[i][j]=0;
                            cheak = true;
                            break;
                        case 'd':
                            System.out.println(j+" d");
                            map[i][j-1]=97;
                            map[i][j]=0;
                            cheak = true;
                            break;
                        default:
                            break;
                    }
                }
                if(cheak){
                    break;
                }
            }
        }
    }
}
