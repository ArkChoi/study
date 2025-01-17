package gugudan;

import java.util.Arrays;

public class Movingpoint {
    public static void main(String[] args){
        int [][] maparray = new int[9][9];
        for(int i=1;i<10;i++){
            for(int j=1;j<10;j++){
                if(i==1){
                    maparray[i-1][j-1]=j;
                }
                else if(j==1){
                    maparray[i-1][j-1]=i;
                }
                maparray[i-1][j-1]=i*j;
            }
        }
        for(int i=0;i<maparray.length;i++){
            System.out.print(Arrays.toString(maparray[i]));
            System.out.println();
        }
        point pointmen = new point("men", 0, 0);
        pointmen.where();
        System.out.println(maparray[pointmen.x][pointmen.y]);
    }
}
