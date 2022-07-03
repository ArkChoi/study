void start();
void Moon(const char Month[]);
void Num(int a, int b);
void interpretation(const char Month[], int a, int b);
#include<stdio.h>

void start(){
    printf("Diary 2022 ");
}

void Moon(const char Month[]){
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

void Num(int a, int b){
    printf(" %c%c",a,b);
}

void interpretation(const char Month[], int a, int b){
    start();
    Moon(Month);
    Num(a,b);
}