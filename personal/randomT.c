#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int a;
    for(int i=0;i<10;i++){
        a=rand();
        printf("%d\n",a%50);
        //a%n �ϋ� 0 ~ (n-1)��ŭ�� ũ�⿡�� �������ڰ� ���´�.
    }
    return 0;
}