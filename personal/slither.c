#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define x_size 43
#define y_size 23

//Ŀ�� �̵� �Լ� ����Ʈ �Ǵ� ��ġ�� �����cs
void gotoxy(int x ,int y){
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}
//���� ����Ʈ ���� �̹���� ���� ��� ���ڰŷ��� ���� ���� ("cls")���� // ���� �Լ��� �ذ� �׷��� �ǹ��� (����Ʈ�� ���ŵǴ°���? || ����Ʈ ��ŭ �޸� �Դ°���?)
int print(int* a){
    //system("cls");
    //printf ������� \b�� �ڷ� ��ĭ �̵��̴�. ���� �ٲ�� ���� �ִ� �ٷ� ���°� �ȵȴ�.
    /*for(int i=0;i<990;i++){
        printf("\b");
    }*/
    gotoxy(0,0);
    for(int i=0;i<y_size;i++){
        for(int j=0;j<x_size;j++){
            if(*a==1001){
                printf("G");//������ ���̸��
            }
            else if(*a==1000){
                printf("#");//�� ���
            }
            else if(*a==0){
                printf(" ");//����
            }
            //���� Ȯ�ο�
            /*
            else if(*a==2){
                printf("2");
            }
            else if(*a==4){
                printf("4");
            }
            */
           //������ �Ӹ�
           else if(*a==1){
                printf("@");
            }
            else{
                printf("O");//������ ����
            }
            a++;
        }
        printf("\n");
    }
}

//��ü �����̸� ����ĭ���� �����̰� ��
int swap(int* a,char d, int e){
    int f,g,b = *a;
    int c=0;
    //������ �Ӹ� ��ġ�� ã��
    while(1){
        b=*(a+c);
        if(b==1){
            break;
        }
        else{
            c++;
        }
    }
    //���� �⵿
    if(d=='d'){
        b=*(a+c+1);
        //���̸� ������
        if(b==1001){
            *(a+c)=0;
            *(a+c+1)=1;
            g=33;
        }
        //���̳� ������ ������ ���� ���� ����(���� �� + ������ ��)
        else if(b!=0){
            return 99;
        }
        //�ƹ��͵� �ƴϸ�
        else{
            *(a+c)=0;
            *(a+c+1)=1;
            g=1;
        }
    }
    //���� �⵿
    if(d=='a'){
        b=*(a+c-1);
        if(b==1001){
            *(a+c)=0;
            *(a+c-1)=1;
            g=33;
        }
        else if(b!=0){
            return 99;
        }
        else{
            *(a+c)=0;
            *(a+c-1)=1;
            g=1;
        }
    }
    //��� �⵿
    if(d=='w'){
        b=*(a+c-x_size);
        if(b==1001){
            *(a+c)=0;
            *(a+c-x_size)=1;;
            g=33;
        }
        else if(b!=0){
            return 99;
        }
        else{
            *(a+c)=0;
            *(a+c-x_size)=1;
            g=1;
        }
    }
    //�Ϻ� �⵿
    if(d=='s'){
        b=*(a+c+x_size);
        if(b==1001){
            *(a+c)=0;
            *(a+c+x_size)=1;
            g=33;
        }
        else if(b!=0){
            return 99;
        }
        else{
            *(a+c)=0;
            *(a+c+x_size)=1;
            g=1;
        }
    }
    if(g==33){
        //���̸� ���� �� 2�϶��� �߰� ����
        if(e==2){
            *(a+c)=e;
            return 33;
        }
        //���̸� ���� �� ���� ���󰡱� 3 �̻�
        for(int i=2;i<e;i++){
            //���� ������ ��ġ�� ����Ŵ
            f=c;
            c=0;
            while(1){
                b=*(a+c);
                if(b==i){
                    break;
                }
                else{
                    c++;
                }
            }
            *(a+c)=e;//������ �̵� ��ġ�� ���ο� ���� ����
            *(a+f)=i;
        }
        return 33;
    }
    else{
        //���� ���󰡱� ���� ������� ��� ������ ���󰡰� ��
        for(int i=2;i<e;i++){
            //���� ������ ��ġ�� ����Ŵ
            f=c;
            c=0;
            //i�� ���ڿ� �´� ���� ��ġ ã��
            while(1){
                b=*(a+c);
                if(b==i){
                    break;
                }
                else{
                 c++;
                }
            }
            *(a+c)=0;//���� �ڸ��� 0 �Է�
            *(a+f)=i;//���� ������ ��ġ�� i���� �Է�
        }
        return 1;
    }
}

//Ű �Է��� ����
int key(){
    char a;
    if(_kbhit()!=0){
        return _getch();
    }
    return 0;
}

//���� ��ġ�� �������� ��������
int random(int *a){
    int b=0;
    while(1){
        if(*(a+b)==0){
            *(a+b)=1001;
            break;
        }
        else{
            b=(rand()%861)+1;
        }
    }
}

int main(){
    //�ܼ�â ũ�� ���� cols=���� lines=���� | Ÿ��Ʋ �̸�
    system("mode con cols=43 lines=24 | title slither");
    //���⼭ ������ ����� ������ �ѹ��� ���� ��
    srand(time(NULL));
    int a,map[y_size][x_size],ran,l,eat=2;
    char b='d',c;
    //ó�� �� �ʱ�ȭ
    for(int i=0;i<y_size;i++){
        for(int j=0;j<x_size;j++){
            if(i==0||j==0||i==y_size-1||j==x_size-1){
                map[i][j]=1000;
            }
            else{
                map[i][j]=0;
            }
        }
    }
    //������ ���� ��ġ
    map[5][10]=1;
    random(&map[0][0]);
    while(1){
        print(&map[0][0]);
        printf("%d",eat-2);
        c=key();
        if(c=='a'||c=='s'||c=='d'||c=='w'){
            b=c;
        }
        //��ġ �ٲٱ� ���� ��ɾ� ��ġ
        a=swap(&map[0][0],b,eat);
        //�Ⱦ��� �ʹ����� ����� �� �Ѿư�;;
        Sleep(50);
        //���� ���� ��
        if(a==99){
            gotoxy(17,11);
            printf("Game Over");
            Sleep(5000);
            break;
        }
        //���� ��� ������ '��'
        if(a==33){
            eat++;
            random(&map[0][0]);
        }
    }
}