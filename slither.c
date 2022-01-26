#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>
#define x_size 43
#define y_size 23

int print(int* a){
    system("cls");
    for(int i=0;i<y_size;i++){
        for(int j=0;j<x_size;j++){
            if(*a==2){
                printf("@");
            }
            else if(*a==9){
                printf("X");
            }
            else if(*a==1){
                printf("O");
            }
            else{
                printf(" ");
            }
            a++;
        }
        printf("\n");
    }
}

int swap(int* a,char d){
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
    if(d=='d'){
        b=*(a+c+1);
        if(b==9){
            return 99;
        }
        else if(b==2){
            *(a+c)=0;
            *(a+c+1)=1;
            return 22;
        }
        else{
            *(a+c)=0;
            *(a+c+1)=1;
            return 1;
        }
    }
    if(d=='a'){
        b=*(a+c-1);
        if(b==9){
            return 99;
        }
        else if(b==2){
            *(a+c)=0;
            *(a+c-1)=1;
            return 22;
        }
        else{
            *(a+c)=0;
            *(a+c-1)=1;
            return 1;
        }
    }
    if(d=='w'){
        b=*(a+c-x_size);
        if(b==9){
            return 99;
        }
        else if(b==2){
            *(a+c)=0;
            *(a+c-x_size)=1;;
            return 22;
        }
        else{
            *(a+c)=0;
            *(a+c-x_size)=1;
            return 1;
        }
    }
    if(d=='s'){
        b=*(a+c+x_size);
        if(b==9){
            return 99;
        }
        else if(b==2){
            *(a+c)=0;
            *(a+c+x_size)=1;
            return 22;
        }
        else{
            *(a+c)=0;
            *(a+c+x_size)=1;
            return 1;
        }
    }
}

int key(){
    char a;
    if(_kbhit()!=0){
        return _getch();
    }
    return 0;
}

int random(int *a){
    int b=0;
    while(1){
        if(*(a+b)==0){
            *(a+b)=2;
            break;
        }
        else{
            b=(rand()%861)+1;
        }
    }
}

int main(){
    srand(time(NULL));
    int map[y_size][x_size],ran,l,test=0;
    char b='d',c;
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
    random(&map[0][0]);
    while(1){
        print(&map[0][0]);
        printf("\n %d",test);
        c=key();
        if(c=='a'||c=='s'||c=='d'||c=='w'){
            b=c;
        }
        int a=swap(&map[0][0],b);
        Sleep(300);
        if(a==99){
            break;
        }
        if(a==22){
            test++;
            random(&map[0][0]);
        }
    }
}