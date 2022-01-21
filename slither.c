#include<stdio.h>
#include<windows.h>
#define x_size 21
#define y_size 11

int print(int* a){
    //system("cls");
    for(int i=0;i<y_size;i++){
        for(int j=0;j<x_size;j++){
            printf("%d",*a);
            a++;
        }
        printf("\n");
    }
}

int swap(int* a){
    int b = *a;
    int c=0;
    while(1){
        b=*(a+c);
        if(b==1){
            break;
        }
        else{
            c++;
        }
    }
    b=*(a+c+1);
    if(b==9){
        return 99;
    }
    else{
        *(a+c)=0;
        *(a+c+1)=1;
    }
}

int main(){
    int map[y_size][x_size];
    for(int i=0;i<y_size;i++){
        for(int j=0;j<x_size;j++){
            if(i==0||j==0||i==y_size-1||j==x_size-1){
                map[i][j]=9;
            }
            else{
                map[i][j]=0;
            }
        }
    }
    map[5][10]=1;
    while(1){
        print(&map[0][0]);
        printf("\n");
        int a=swap(&map[0][0]);
        if(a==99){
            break;
        }
    }
}