#include <stdio.h>
#include <windows.h>
#define x_size 3
#define y_size 3
/*
메모리 위치 확인 코드
    printf("\n")
    for(int i=0;i<y_size;i++){
         or(int j=0;j<x_size;j++){
            printf("%p and ",&map[i][j]);
        }
        printf("\n1\n");
    }
*/

int game_over(int* a){
    int move=1;
    for(int i=0;i<9;i++){
        move *= *(a+i);
    }
    if(move!=0){
        return 3;
    }
    else{
        move = 0;
    }
    for(int i=0;i<3;i++){
        if(*(a+move)**(a+1+move)**(a+2+move)==1||*(a+move)**(a+1+move)**(a+2+move)==8){
            return *(a+move);
            break;
        }
        else{
            move+=3;
        }
    }
    for(int i=0;i<3;i++){
        if(*(a+i)**(a+3+i)**(a+6+i)==1||*(a+i)**(a+3+i)**(a+6+i)==8){
            return *(a+i);
            break;
        }
    }
    if(*a**(a+4)**(a+8)==1||*a**(a+4)**(a+8)==8){
        return *a;
    }
    else if(*(a+2)**(a+4)**(a+6)==1||*(a+2)**(a+4)**(a+6)==8){
        return *(a+2);
    }
    else{
        return 0;
    }
}

int print(int* a){
    //터미널 화면 지우기 windows 라이브러리 명령어
    system("cls");
    int move=0;
    for(int i=0;i<y_size;i++){
        for (int j=0;j<x_size;j++){
            if(*(a+move)==1){
                printf("O");
            }
            else if(*(a+move)==2){
                printf("X");
            }
            else{
                printf("*");
            }
            move++;
        }
        printf("\n");
    }
}

int main(){
    int a,b,turn=0,map[y_size][x_size]={0,0,0,0,0,0,0,0,0};
    while(1){
        print(&map[0][0]);
        printf("\nPlease keep the 'x_Num,y_Num'.\n%d Player turn\n",(turn%2+1));
        turn++;
        scanf("%d,%d",&a,&b);
        if (a>x_size||b>y_size||a<1||b<1){
            printf("\nPlease keep the '1~3,1~3'.\n");
            turn--;
        }
        else if(map[b-1][a-1]==0){
            if(turn%2==1){
                map[b-1][a-1]=1;
            }
            else{
                map[b-1][a-1]=2;
            }
            printf("\n");
        }
        else{
            printf("\nagain please\n");
            turn--;
        }
        if(game_over(&map[0][0])==1||game_over(&map[0][0])==2){
            print(&map[0][0]);
            printf("%d player winner!",game_over(&map[0][0]));
            break;
        }
        else if(game_over(&map[0][0])==3){
            print(&map[0][0]);
            printf("Game Over");
            break;
        }
    }
    //윈도우용 대기(ms단위)(1000=1초)
    Sleep(5000);
    //Linux용 대기(s단위)
    //sleep(30); 주의 소문자's'임
    return 0;
}