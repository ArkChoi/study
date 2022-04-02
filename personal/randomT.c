#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int a;
    for(int i=0;i<10;i++){
        a=rand();
        printf("%d\n",a%50);
        //a%n 일떄 0 ~ (n-1)만큼의 크기에서 랜덤숫자가 나온다.
    }
    return 0;
}