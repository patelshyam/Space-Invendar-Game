#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct past{

char name[15];
char score[15];
char fname[20][20];

}a;


void setcoord(int x,int y);
void border();
void welcome();
void side();
void read();
void tank(char aero);
void blank_tank(int x);
void target();
void s_display();
void print(int,int);
void load();

int x,y,p,q,score=0;
int sizex = 45;
int user=1;
char fname[15];
char oname[15][15];
int sizey = 15;
int total_Enemy = 0,current_Enemy = 0;
char player = 'A';
char playerLaser = '^';
char enemy = 'M';
char enemyShild = 'O';
char enemyLaser = 'U';
char explosion = 'X';
char letter[100][100];
int sort[10];

COORD c ={0,0};
int main()
{
    char e;
    p=26,q=11;
    char aero;
    int s=1;
    welcome();
      load();
     target();

    while(1){
     side();
    border();
    if(s % 90 == 0 && s != 370)
    {
        q++;
    }
    else if(s == 370 || current_Enemy == 0)
    {

        break;
    }
    print(p,q);
    tank(aero);
    Sleep(30);
    aero = NULL;
    if(kbhit())
    {
        aero = getch();
    }
    system("cls");
    s++;
     }
     read();

     if(s == 370 && current_Enemy != 0)
     {
         int i;
         s_display();
        printf("If You Want To Exit Then You Have to Press 'e'");
         getch();
     }
     else
     {
         system("cls");
         printf("\n\n -------------------------------------------------------------------------------------------------------\n\n");

         printf("\n\n\n\t Congo You won the game %s",a.name);
         printf("\n\n -------------------------------------------------------------------------------------------------------\n\n");

     }


    return 0;
}

void welcome(){

int z=0;
printf("Enter Your name : >>\n ",a.name);
scanf("%s",a.name);
strcpy(a.fname[z],a.name);
z++;
}

void side(){

setcoord(90,13);
printf("--------------------------");
setcoord(93,15);
printf("Player name : %s ",a.name);
setcoord(93,17);
printf("Current score : %d ",score);
setcoord(93,19);
printf("Target : %d",current_Enemy);
setcoord(90,21);
printf("---------------------------");
}
void read(){

    int i;
    strcpy(fname,a.name);
    strcpy(oname,a.name);

        FILE *fp;
        strcat(fname,".txt");
        fp = fopen(a.name,"w");
        fprintf(fp,"%d",score);
        fclose(fp);

        FILE *fp1;
        fp1 = fopen("score.txt","a+");
        fprintf(fp1,"%d ",score);
        fclose(fp1);


        FILE *fp3;
        fp3 = fopen("name.txt","a+");
        fprintf(fp3,"%s ",oname);
        fclose(fp3);


        FILE *fp2;
        fp2 = fopen("score.txt","r");
        fscanf(fp2,"%d %d %d %d %d %d %d %d %d %d",&sort[0],&sort[1],&sort[2],&sort[3],&sort[4],&sort[5],&sort[6],&sort[7],&sort[8],&sort[9],&sort[10]);
        fclose(fp2);

}




void setcoord(int x,int y){

c.X=x; c.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);//for set coords
}

void border(){

int i,x=27,y=10;
for(i=0; i<25; i++)
{
    setcoord(25,y);//for printing the border with #
    printf("#");
    y++;
}
for(i=0; i<30; i++)
{
    setcoord(x,10);
    printf("#");
    x+=2;
}
y=10;
for(i=0; i<25; i++)
{
    setcoord(87,y);
    printf("#");
    y++;
}
x=27;
for(i=0; i<30; i++)
{
    setcoord(x,34);
    printf("#");
    x+=2;
}

}


int i,x=50,y=28;
void tank(char aero)
{

    char star[2][500]={"=================","================"};
    y=24;
    for(i=0; i<4;i++)
    {
    setcoord(x+9,y);
    printf("+");
    y++;
    }
    setcoord(x,28);
    printf("%s",star[0]);
      y=28;
    for(i=0; i<5;i++)
    {
    setcoord(x,y);
    printf("[");
    y++;
    }
    setcoord(x+1,32);
    printf("%s",star[1]);
    for(i=0; i<5;i++)
    {
    setcoord(x+17,y-5);
    printf("]");
    y++;
    }
    if((aero == 'a' || aero == 'A') && x != 26)
    {
        x--;
        aero=NULL;
    }
    else if((aero == 'd' || aero == 'D') && x != 69)
    {
        x++;
        aero=NULL;
    }
    else if(aero == 'm' || aero == 'M')
    {
        y=24;
        for(i=0; i<14; i++)
        {
        setcoord(x+9,y);
        if(letter[y][x+9] == enemy || letter[y][x+9] == enemyShild)
        {
            score++;
            if(letter[y][x+9] == enemy){
            letter[y][x+9] = ' ';
             current_Enemy--;
            break;

            }
            else if(letter[y][x+9] == enemyShild)
            {
                letter[y][x+9] = enemy;
                current_Enemy--;
                break;
            }

        }
        printf("%c",playerLaser);
        y--;
        Sleep(5);
        }
    }
}
void load(){
    system("cls");
    int row,col,r,c,q;
    setcoord(36,13);
    printf("Good luck %s",a.name);
    setcoord(36,15);
    printf("You have to break the minimum score of 50",a.name);
    setcoord(36,17);
    fprintf(stderr,"loading...");
    setcoord(30,19);
    for(r=1;r<=20;r++){
    Sleep(150);//to display the character slowly
    fprintf(stderr,"%c",177);}

}



void target()
{
int i,j;

for(i=11; i<33; i++)
{
    for(j=26; j<87; j++)
    {
        if(i > 13 && j % 2 == 0 && i < 18 && j < 80 && j > 34){
    letter[i][j] = enemy;
    total_Enemy++;
        }
        else if(i >= 18 && j % 2 == 0 && i < 19 && j < 80 && j > 34){
    letter[i][j] = enemyShild;
    total_Enemy+=2;
        }
    else
    {
        letter[i][j] = ' ';
    }
    }
}
current_Enemy = total_Enemy;
}
int j,t=33;
void print(int p,int q)
{

    for(i=11; i<t; i++)
    {
        if(i % 30 == 0 && t != q){
            t--;
        }
        setcoord(p,q);
        for(j=26; j<87; j++)
        {
            printf("%c",letter[i][j]);
        }
        q++;
        printf("\n");
    }
}

void s_display(){

int i,max;
max = sort[0];
for(i=0;i<10;i++){


    if( max < sort[i]){

       max = sort[i];

}

}
         system("cls");
         printf("\n\n\t\t\t\t\t SCORE LIST \n");
         printf("\n\n -------------------------------------------------------------------------------------------------------\n\n");
         setcoord(60,5);
         printf("\t\t Top score -- > %d ",max);
         printf("\n\n\n\t %s your  score  is -- > %d ",a.name,score);
         printf("\n\n -------------------------------------------------------------------------------------------------------\n\n");


}







