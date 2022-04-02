#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define x_size 43
#define y_size 23

//커서 이동 함수 프린트 되는 위치를 잡아줌cs
void gotoxy(int x ,int y){
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}
//맵을 프린트 해줌 이방법은 지금 계속 깜박거려서 눈이 아픔 ("cls")쓸떄 // 위의 함수로 해결 그러나 의문은 (프린트시 제거되는거임? || 프린트 만큼 메모리 먹는거임?)
int print(int* a){
    //system("cls");
    //printf 제어문자중 \b는 뒤로 한칸 이동이다. 줄이 바뀌면 전에 있던 줄로 가는건 안된다.
    /*for(int i=0;i<990;i++){
        printf("\b");
    }*/
    gotoxy(0,0);
    for(int i=0;i<y_size;i++){
        for(int j=0;j<x_size;j++){
            if(*a==1001){
                printf("G");//지렁이 먹이모양
            }
            else if(*a==1000){
                printf("#");//벽 모양
            }
            else if(*a==0){
                printf(" ");//공백
            }
            //꼬리 확인용
            /*
            else if(*a==2){
                printf("2");
            }
            else if(*a==4){
                printf("4");
            }
            */
           //지렁이 머리
           else if(*a==1){
                printf("@");
            }
            else{
                printf("O");//지렁이 꼬리
            }
            a++;
        }
        printf("\n");
    }
}

//본체 지렁이를 다음칸으로 움직이게 함
int swap(int* a,char d, int e){
    int f,g,b = *a;
    int c=0;
    //지렁이 머리 위치를 찾음
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
        //먹이를 먹으면
        if(b==1001){
            *(a+c)=0;
            *(a+c+1)=1;
            g=33;
        }
        //벽이나 꼬리에 만나면 게임 오버 조건(벽에 담 + 꼬리에 담)
        else if(b!=0){
            return 99;
        }
        //아무것도 아니면
        else{
            *(a+c)=0;
            *(a+c+1)=1;
            g=1;
        }
    }
    //좌측 기동
    if(d=='a'){
        b=*(a+c-1);
        if(b==1001){
            *(a+c)=0;
            *(a+c-1)=1;
            g=33;
        }
        else if(b!=0){
            return 99;
        }
        else{
            *(a+c)=0;
            *(a+c-1)=1;
            g=1;
        }
    }
    //상부 기동
    if(d=='w'){
        b=*(a+c-x_size);
        if(b==1001){
            *(a+c)=0;
            *(a+c-x_size)=1;;
            g=33;
        }
        else if(b!=0){
            return 99;
        }
        else{
            *(a+c)=0;
            *(a+c-x_size)=1;
            g=1;
        }
    }
    //하부 기동
    if(d=='s'){
        b=*(a+c+x_size);
        if(b==1001){
            *(a+c)=0;
            *(a+c+x_size)=1;
            g=33;
        }
        else if(b!=0){
            return 99;
        }
        else{
            *(a+c)=0;
            *(a+c+x_size)=1;
            g=1;
        }
    }
    if(g==33){
        //먹이를 먹은 후 2일때는 추가 생성
        if(e==2){
            *(a+c)=e;
            return 33;
        }
        //먹이를 먹은 후 꼬리 따라가기 3 이상
        for(int i=2;i<e;i++){
            //전의 지렁이 위치를 기억시킴
            f=c;
            c=0;
            while(1){
                b=*(a+c);
                if(b==i){
                    break;
                }
                else{
                    c++;
                }
            }
            *(a+c)=e;//마지막 이동 위치에 새로운 숫자 투입
            *(a+f)=i;
        }
        return 33;
    }
    else{
        //꼬리 따라가기 갯수 상관없는 모든 꼬리를 따라가게 함
        for(int i=2;i<e;i++){
            //전의 지렁이 위치를 기억시킴
            f=c;
            c=0;
            //i의 숫자에 맞는 꼬리 위치 찾기
            while(1){
                b=*(a+c);
                if(b==i){
                    break;
                }
                else{
                 c++;
                }
            }
            *(a+c)=0;//본래 자리에 0 입력
            *(a+f)=i;//전의 지렁이 위치에 i값을 입력
        }
        return 1;
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
            *(a+b)=1001;
            break;
        }
        else{
            b=(rand()%861)+1;
        }
    }
}

int main(){
    //콘솔창 크기 지정 cols=가로 lines=세로 | 타이틀 이름
    system("mode con cols=43 lines=24 | title slither");
    //여기서 선언을 해줘야 랜덤이 한번만 정의 됨
    srand(time(NULL));
    int a,map[y_size][x_size],ran,l,eat=2;
    char b='d',c;
    //처음 맵 초기화
    for(int i=0;i<y_size;i++){
        for(int j=0;j<x_size;j++){
            if(i==0||j==0||i==y_size-1||j==x_size-1){
                map[i][j]=1000;
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
        printf("%d",eat-2);
        c=key();
        if(c=='a'||c=='s'||c=='d'||c=='w'){
            b=c;
        }
        //위치 바꾸기 실행 명령어 위치
        a=swap(&map[0][0],b,eat);
        //안쓰면 너무빨라서 사람이 못 쫓아감;;
        Sleep(50);
        //게임 오버 시
        if(a==99){
            gotoxy(17,11);
            printf("Game Over");
            Sleep(5000);
            break;
        }
        //먹이 얌얌 새먹이 '줘'
        if(a==33){
            eat++;
            random(&map[0][0]);
        }
    }
}