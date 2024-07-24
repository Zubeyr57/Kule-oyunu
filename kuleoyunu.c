#include <stdio.h>
#include <conio.h>                                                     /*Klavye ve ekran kullanimi icin gerekli fonksiyonlari barindirir*/
#include <windows.h>                                                   /*windows komutlarini kullanmamizi saglar*/

int characterx=12;
int charactery;
unsigned char Tus;
int tbasson_x;
int tbasson_y;
int yninbiralt;
int can=3;
int puan;
int durum=1;
int cerceve_boyut[80][23]={0};



void hidecursor(){
	CONSOLE_CURSOR_INFO cursor_info={1,0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);	
}

 
void gotoxy(short x, short y) {
HANDLE hConsoleOutput;
COORD Cursor_Pos = {x-1, y-1};
hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}


void cerceve(int x1, int y1, int x2, int y2,int certip){               /*cerceveyi olusturan alt program*/
int i;
for(i=x1; i<=x2;i++){
    cerceve_boyut[i][y1] = certip;
    cerceve_boyut[i][y2] = certip;
}
for(i=y1; i<=y2;i++){
    cerceve_boyut[x1][i] = certip;
    cerceve_boyut[x2][i] = certip;
}
}


void ekrani_bas(){                                                     /*cerceveyi ekrana basan alt program*/
int x,y;

for(x=0;x<80;x++){

    for(y=0;y<23;y++){
        gotoxy(x+1,y+1);
if(cerceve_boyut[x][y]==1){
    printf("%c",219);
}
else if(cerceve_boyut[x][y]==2){
    printf("%c",176);
}
else if(cerceve_boyut[x][y]==3){
    printf("%c",88);
}}}}


void can3(){

if(puan<=4){
yninbiralt=charactery+1; 
gotoxy(40,yninbiralt);
 printf("%c%c%c%c%c%c%c%c",178,178,178,178,178,178,178,178);           /*karekterin bir altina kule blogunu yerlestirir*/
gotoxy(characterx,charactery);                                         /*hareket eden karekteri burada olusturuyoruz*/
 printf("%c%c%c%c%c%c%c%c",178,178,178,178,178,178,178,178);
 Sleep(100);
gotoxy(characterx,charactery);
 printf("          ");
}
if(4<puan){
    if(puan<8){
        yninbiralt=charactery+1; 
        gotoxy(40,yninbiralt);
         printf("%c%c%c%c%c%c%c%c",178,178,178,178,178,178,178,178);          
        gotoxy(characterx,charactery);                   
         printf("%c%c%c%c%c%c%c%c",178,178,178,178,178,178,178,178);
         Sleep(70);
        gotoxy(characterx,charactery);
         printf("          ");
}}
if(8<=puan){
yninbiralt=charactery+1; 
gotoxy(40,yninbiralt);
 printf("%c%c%c%c%c%c%c%c",178,178,178,178,178,178,178,178);          
gotoxy(characterx,charactery);                   
 printf("%c%c%c%c%c%c%c%c",178,178,178,178,178,178,178,178);
 Sleep(60);
gotoxy(characterx,charactery);
 printf("          ");
}

}


void can2(){
if(puan<=4){
yninbiralt=charactery+1; 
gotoxy(42,yninbiralt);
 printf("%c%c%c%c%c%c",178,178,178,178,178,178);                       /*karekterin bir altina kule blogunu yerlestirir*/
gotoxy(characterx,charactery);                                         /*hareket eden karekteri burada olusturuyoruz*/
 printf("%c%c%c%c%c%c",178,178,178,178,178,178);
 Sleep(100);
gotoxy(characterx,charactery);
 printf("      ");
}
if(4<puan){
    if(puan<8){
        yninbiralt=charactery+1; 
        gotoxy(42,yninbiralt);
         printf("%c%c%c%c%c%C",178,178,178,178,178,178);          
        gotoxy(characterx,charactery);                   
         printf("%c%c%c%c%c%C",178,178,178,178,178,178);
         Sleep(70);
        gotoxy(characterx,charactery);
         printf("      ");
}}
if(8<=puan){
yninbiralt=charactery+1; 
gotoxy(42,yninbiralt);
 printf("%c%c%c%c%c%c",178,178,178,178,178,178);          
gotoxy(characterx,charactery);                   
 printf("%c%c%c%c%c%C",178,178,178,178,178,178);
 Sleep(60);
gotoxy(characterx,charactery);
 printf("      ");
} 
}


void main(){
cerceve(0,0,79,22,1);                                                  /*cercevenin boyutlarini giriyoruz*/
ekrani_bas();                                                          /*cerceveyi ekrana basan alt program*/
hidecursor();                    

charactery=20;

do{
int check=41;

if(kbhit()){
    Tus=getch();
    if(Tus==224){
        Tus=getch();
        if (Tus==72){
            switch (can){
                case 3: check=41;
                    break;
                case 2: check=check+2;
                    break;
                default: check=check+2;
    }    
            if(characterx==check){                                     /*ust ok tusu*/
                charactery=charactery-1;
                puan=puan+1;
            }
            else can=can-1;                                                                       
}}}
switch(can){
    case 3: can3();
        break;    
    case 2: can2();
        break;    
    case 1: can2();                     
}


if(characterx>50)                                                      /*cercevenin sinirlarini belirliyoruz*/
    characterx=17;
if(characterx<2)
    characterx=76;
if(charactery>22)
    charactery=2;
if(charactery<2)
    charactery=22;

gotoxy(2,2);
    printf("%s%d","Puan = ",puan);

characterx=characterx+1;
gotoxy(38,2);
    printf("%s%d","Can = ",can);

if(can==0){
    gotoxy(25,16);
        printf("%s","KAYBETTINIZ");
        Sleep(1000);
        durum=0;
}
if(puan==18){
    gotoxy(36,16);
        printf("%s","MAX PUAN");
        Sleep(1000);
        durum=0;
}
} while (durum==1);

}/*158*/