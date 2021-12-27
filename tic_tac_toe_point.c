#include<stdio.h>
#define x_size 3
#define y_size 3

int main(){
re:
   for(int i=0;i<y_size;i++){
       for (int j=0;j<x_size;j++){
           printf("*");
       }
       printf("\n");
   }
//메모리 위치 확인 코드
//     printf("\n")
//     for(int i=0;i<y_size;i++){
//         for(int j=0;j<x_size;j++){
//              printf("%p and ",&map[i][j]);
//          }
//          printf("\n1\n");
//      }
   printf("\nPlease keep the 'x_Num,y_Num'.");
   int a,b,winner,turn=0,map[y_size][x_size]={0,0,0,0,0,0,0,0,0};
   int* where=&map[0][0];
   while(1){
       int gmae_over=0,move=0;
       turn++;
       printf("\n");
       scanf("%d,%d",&a,&b);
       if(a==0&&b==0){
           break;
       }
       else if (a>x_size||b>y_size||a<1||b<1){
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
            for(int i=1;i<y_size+1;i++){
                for (int j=1;j<x_size+1;j++){
                    if(map[i-1][j-1]==1){
                        printf("O");
                    }
                    else if(map[i-1][j-1]==2){
                        printf("X");
                    }
                    else{
                        printf("*");
                    }
                }
                printf("\n");
            }
            gmae_over=1;
            for(int i=0;i<9;i++){
                gmae_over*= *(where+i);
            }
            if(gmae_over!=0){
                printf("\nGame Over\nyour play turn is %d",turn);
                break;
            }
            move=0;
            gmae_over=1;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                gmae_over*= *(where+j);
                }
                if(gmae_over==1){
                    winner=1;
                    printf("\nWinner is 1 Player");
                    break;
                }
                else if(gmae_over==8){
                    winner=2;
                    printf("\nWinner is 2 Player");
                    break;
                }
                else{
                    gmae_over=1;
                    winner=0;
                }
            }
            if(winner==1||winner==2){
                break;
            }
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                gmae_over*= *(where+move);
                move+=3;
                }
                if(gmae_over==1){
                    winner=1;
                    printf("\nWinner is 1 Player");
                    break;
                }
                else if(gmae_over==8){
                    winner=2;
                    printf("\nWinner is 2 Player");
                    break;
                }
                else{
                    gmae_over=1;
                    move-=5;
                    winner=0;
                }
            }
            if(winner==1||winner==2){
                break;
            }
            if (*where**(where+4)**(where+8)==1||*(where+2)**(where+4)**(where+6)==1){
                printf("\nWinner is 1 Player");
                break;
            }
            else if(*where**(where+4)**(where+8)==8||*(where+2)**(where+4)**(where+6)==8){
                printf("\nWinner is 2 Player");
                break;
            }
        }
        else{
            printf("\nagain please\n");
            turn--;
        }
    }
    char again;
    printf("\nDo you want play again?(y/n)\n");
    scanf("%s",&again);
    if(again=='y'){
        printf("again go!\n");
        goto re;
    }
    else{
        return 0;
    }
}