#include <stdio.h>

int StartMenu 1
int GamePlay 1

void print_Start();

int main(){
    while (StartMenu){
        print_Start();
        //키보드 인풋을 통한 A,D 이동과 enter 결정을 만들어 보자
    }
    
    return 0;
}

void print_Start(){
    printf("   ---   HELLDIVERS 2 Stratagem Training   ---   \n");
    printf("\n\n\n\n\n");
    if(CheckNum==1){
        printf("                - Start / Quit\n");
    }
    else{
        printf("                  Start / - Quit\n");
    }
}