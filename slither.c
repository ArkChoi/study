#include<stdio.h>
#define x_size 11
#define y_size 11

int main(){
    int ary[y_size][x_size];
    for(int i=0;i<y_size;i++){
        for(int j=0;j<x_size;j++){
            if(i==0||j==0||i==y_size-1||j==x_size-1){
                ary[i][j]=9;
            }
            else{
                ary[i][j]=0;
            }
        }
    }
    for(int i=0;i<y_size;i++){
        for(int j=0;j<x_size;j++){
            printf("%d",ary[i][j]);
        }
        printf("\n");
    }
}