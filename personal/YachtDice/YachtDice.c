#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#define DSize 7
int remember[5]={0,};

//�ӽ� key set wasd ���, k = keep on/off ��ɰ� ���� ����, r = �ֻ��� ������

//We will the wall Dice And Reset
int WallD(int *a);
//The dice is cast
int RandomDice(int *a);
//Key input
int key();
//Print location
void gotoxy(int x, int y);
//KeepNum you want numbers
void KeepNum(int *x,int y);

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
        else if(keyinput=='k'){
            printf("1~5���� ������ �ּ��� : ?\b");
            scanf("%d",&keyinput);
            KeepNum(dice[3],keyinput);
            gotoxy(0,7);
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
    for(int i=0;i<5;i++){
            //dice keep num setting
            if(remember[i]!=0){
                *(a+1+i)=remember[i];
            }
        }
    gotoxy(0,0);
    //a�� ������ġ�� �迭�� 3��° ���̹Ƿ� ó������ ������
    a-=(DSize*3);
    //Dice���
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

//Ű �Է��� ����
int key(){
    char a;
    if(_kbhit()!=0){
        return _getch();
    }
    return 0;
}

void gotoxy (int x /*x�� ��ġ*/,int y /*y�� ��ġ*/){
    COORD Pos;
    Pos.X = x; //������ x ��ġ
    Pos.Y = y; //������ y ��ġ
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}

void KeepNum(int *x,int y){
    switch(y){
    case 1:
        if(remember[0]==0){
            remember[0]=*(x+1);
        }
        else{
            remember[0]=0;
        }
        break;
    case 2:
        if(remember[1]==0){
            remember[1]=*(x+2);
        }
        else{
            remember[1]=0;
        }
        break;
    case 3:
        if(remember[2]==0){
            remember[2]=*(x+3);
        }
        else{
            remember[2]=0;
        }
        break;
    case 4:
        if(remember[3]==0){
            remember[3]=*(x+4);
        }
        else{
            remember[3]=0;
        }
        break;
    case 5:
        if(remember[4]==0){
            remember[4]=*(x+5);
        }
        else{
            remember[4]=0;
        }
        break;
    default:
        break;
    }
}