#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define x_size 43
#define y_size 23

//커서 이동 함수
void gotoxy(int x ,int y){
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}
//맵을 프린트 해줌 이방법은 지금 계속 깜박거려서 눈이 아픔 ("cls")쓸떄 // 위의 함수로 해결 그러나 의문은 (프린트시 제거되는거임? || 프린트 만큼 메모리 먹는거임?)
int print(int* a){
    //system("cls");
    //printf 제어문자중 \b는 뒤로 한칸 이동이다. 줄이 바뀌면 적용이 안된다.
    /*for(int i=0;i<990;i++){
        printf("\b");
    }*/
    gotoxy(0,0);
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

//본체 지렁이를 다음칸으로 움직이게 함
int swap(int* a,char d){
    int b = *a;
    int c=0;
    //지렁이 위치를 찾음
    while(1){
        b=*(a+c);
        if(b==1){
            break;
        }
        else{
            c++;
        }
    }
    //우측 기동
    if(d=='d'){
        b=*(a+c+1);
        //벽에 다으면
        if(b==9){
            return 99;
        }
        //먹이를 먹으면
        else if(b==2){
            *(a+c)=0;
            *(a+c+1)=1;
            return 22;
        }
        //아무것도 없으면
        else{
            *(a+c)=0;
            *(a+c+1)=1;
            return 1;
        }
    }
    //좌측 기동
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
    //상부 기동
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
    //하부 기동
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

//키 입력을 받음
int key(){
    char a;
    if(_kbhit()!=0){
        return _getch();
    }
    return 0;
}

//먹이 위치를 랜덤으로 지정해줌
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
    //콘솔창 크기 지정 cols=가로 lines=세로
    system("mode con cols=43 lines=24 | title slither");
    //여기서 선언을 해줘야 랜덤이 제대로 정의 됨
    srand(time(NULL));
    int map[y_size][x_size],ran,l,test=0;
    char b='d',c;
    //처음 맵 초기화
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
    //지렁이 시작 위치
    map[5][10]=1;
    random(&map[0][0]);
    while(1){
        print(&map[0][0]);
        printf("%d",test);
        c=key();
        if(c=='a'||c=='s'||c=='d'||c=='w'){
            b=c;
        }
        int a=swap(&map[0][0],b);
        //안쓰면 너무빨라서 사람이 못 쫓아감;;
        Sleep(100);
        //게임 오버 조건(벽에 담)
        if(a==99){
            gotoxy(17,11);
            printf("Game Over");
            Sleep(5000);
            break;
        }
        //먹이 얌얌 새먹이 '줘'
        if(a==22){
            test++;
            random(&map[0][0]);
        }
    }
}