#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#define DSize 7

//임시 key set wasd 사용, k = keep on/off 기능과 점수 선택, r = 주사위 던지기

//We will the wall Dice And Reset
int WallD(int *a);
//The dice is cast
int RandomDice(int *a);
//Key input
int key();
//Print location
void gotoxy(int x, int y);

int main(){
    //Right Slot Machine Array
    int dice[DSize][DSize], Map[17][2];
    int keyinput;
    srand(time(NULL));
    WallD(&dice[0][0]);
    while(1){
        keyinput=key();
        if(keyinput == 'r'|| keyinput == 'R'){
            RandomDice(dice[3]);
        }
        else if(keyinput == 'q'){
            break;
        }
    }
}

int WallD(int *a){
    for(int i=0;i<DSize;i++){
        for(int j=0;j<DSize;j++){
            if(i==0||i==DSize-1){
                *a=45;
            }
            else if(j==0||j==DSize-1){
                *a=124;
            }
            else{
                *a=0;
            }
            a++;
        }
    }
    return 0;
}

int RandomDice(int *a){
    for(int i=1;i<6;i++){
        //dice num setting
        *(a+i)=rand()%6+1;
    }
    gotoxy(0,0);
    //a를 받은위치는 배열의 3번째 줄이므로 처음으로 돌려줌
    a-=(DSize*3);
    //Dice출력
    for(int i=0;i<DSize;i++){
        for(int j=0;j<DSize;j++){
            // wall print
            if(i==0||j==0||i==DSize-1||j==DSize-1){
                printf("%c ",*(a)++);
            }
            // Slot Machine print
            else{
                printf("%d ",*(a)++);
            }
        }
        printf("\n");
    }
    return 0;
}

//키 입력을 받음
int key(){
    char a;
    if(_kbhit()!=0){
        return _getch();
    }
    return 0;
}

void gotoxy (int x /*x의 위치*/,int y /*y의 위치*/){
    COORD Pos;
    Pos.X = x; //움직일 x 위치
    Pos.Y = y; //움직일 y 위치
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}
