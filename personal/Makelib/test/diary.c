#include<stdio.h>
#include "diary.h"

void start(int a, int b, char c[10], int d, int e){
    printf("Diary %s/%s%s/%s%s",c,d,e,a,b);
}

void CalendarMonth(const char Month[13]){
    if(Month=="abrams"){
        printf("January");
    }
    else if(Month=="blackpanther"){
        printf("February");
    }
    else if(Month=="stuart"){
        printf("March");
    }
    else if(Month=="sherman"){
        printf("April");
    }
    else if(Month=="sheridan"){
        printf("May");
    }
    else if(Month=="tiger"){
        printf("June");
    }
    else if(Month=="priest"){
        printf("July");
    }
    else if(Month=="puma"){
        printf("August");
    }
    else if(Month=="thunder"){
        printf("September");
    }
    else if(Month=="wolverine"){
        printf("October");
    }
    else if(Month=="leopard"){
        printf("November");
    }
    else if(Month=="redback"){
        printf("December");
    }
    else{
        return ;
    }
}

char Cryptanalysis(char a[]){

}