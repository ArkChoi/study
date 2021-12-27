#include<stdio.h>

int main(){
    int a=0,sum=0,pl=0,ary[3][3]={0,1,2,3,4,5,6,7,8};
    int* p;
    p=&ary[0][0];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%p and ",&ary[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<9;i++){
        printf("%d\n",*(p+i));
        sum+=*(p+i);
    }
    printf("\n%d",sum);
    return 0;
}